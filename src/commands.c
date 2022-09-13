/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:27:28 by matcardo          #+#    #+#             */
/*   Updated: 2022/09/13 17:48:35 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_command_path(char *cmd, char *paths[])
{
	char	*target;
	char	*tmp;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		target = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(target, F_OK) == 0)
			return (target);
		free(target);
		paths++;
	}
	return (NULL);
}

char	**get_paths(char **envp)
{
	char	**paths;

	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	paths = ft_split(*envp + 5, ':');
	return (paths);
}

void	exec_command(char *cmd_str, char *envp[])
{
	char	**cmd_array;
	char	*cmd_path;
	char	**paths;
	int	i;

	paths = get_paths(envp);
	cmd_array = ft_split(cmd_str, ' ');
	cmd_path = get_command_path(cmd_array[0], paths);
	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
	if (!cmd_path)
	{
		i = 0;
		while (cmd_array[i])
			free(cmd_array[i++]);
		free(cmd_array);
		cmd_str = ft_strjoin(cmd_str, ": command not found\n");
		write(2, cmd_str, ft_strlen(cmd_str));
		free(cmd_str);
		exit(127);
	}
	execve(cmd_path, cmd_array, envp);
}

void	exec_commands(char *argv[], char *envp[])
{
	int		file_fd;
	int		pid;
	int		pipe_fd[2];

	if (pipe(pipe_fd) < 0)
		handle_error("Error", EFAULT, EXIT_FAILURE);
	pid = fork();
	if (pid < 0)
		handle_error("Error", EAGAIN, EXIT_FAILURE);
	if (pid == 0)
	{
		file_fd = open(argv[1], O_RDONLY);
		if (file_fd < 0)
			handle_error(argv[1], ENOENT, EXIT_FAILURE);
		dup2(file_fd, STDIN_FILENO);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(file_fd);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		exec_command(argv[2], envp);
	}
	waitpid(pid, NULL, 0);
	file_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	close(pipe_fd[1]);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(file_fd, STDOUT_FILENO);
	close(file_fd);
	close(pipe_fd[0]);
	exec_command(argv[3], envp);
}
