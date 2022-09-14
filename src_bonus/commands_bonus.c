/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:27:28 by matcardo          #+#    #+#             */
/*   Updated: 2022/09/14 16:18:05 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	write_outfile(int file_fd)
{
	char	*str;

	str = get_next_line(STDIN_FILENO);
	while (str)
	{
		write(STDOUT_FILENO, str, ft_strlen(str));
		free(str);
		str = get_next_line(STDIN_FILENO);
	}
	close(file_fd);
}

char	*create_str_error(char *cmd_name)
{
	char	*temp;
	char	*target;

	temp = ft_strjoin("pipex: ", cmd_name);
	target = ft_strjoin(temp, ": command not found\n");
	free(temp);
	return (target);
}

void	exec_command(char *cmd_str, char *envp[])
{
	char	**cmd_array;
	char	**paths;
	char	*cmd_path;
	char	*str_error;
	int		i;

	paths = get_paths(envp);
	cmd_array = ft_split(cmd_str, ' ');
	cmd_path = get_command_path(cmd_array[0], paths);
	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
	if (!cmd_path)
	{
		str_error = create_str_error(cmd_array[0]);
		i = 0;
		while (cmd_array[i])
			free(cmd_array[i++]);
		free(cmd_array);
		write(2, str_error, ft_strlen(str_error));
		free(str_error);
		exit(127);
	}
	execve(cmd_path, cmd_array, envp);
}

void	exec_pipe(int id, int pipe_fd[2], char *cmd, char *envp[])
{
	if (id == 0)
	{	
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		exec_command(cmd, envp);
	}
	else
	{
		waitpid(id, NULL, 0);
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
	}
}

void	exec_commands(int argc, char *argv[], char *envp[])
{
	int	file_fd;
	int	pid;
	int	pipe_fd[2];
	int	index;

	file_fd = open(argv[1], O_RDONLY);
	if (file_fd < 0)
		handle_error(argv[1], EXIT_FAILURE);
	dup2(file_fd, STDIN_FILENO);
	close(file_fd);
	index = 1;
	while (++index <= (argc - 2))
	{
		if (pipe(pipe_fd) < 0)
			handle_error("error", EXIT_FAILURE);
		pid = fork();
		if (pid < 0)
			handle_error("error", EXIT_FAILURE);
		exec_pipe(pid, pipe_fd, argv[index], envp);
	}
	file_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_fd < 0)
		handle_error(argv[argc - 1], EXIT_FAILURE);
	dup2(file_fd, STDOUT_FILENO);
	write_outfile(file_fd);
}
