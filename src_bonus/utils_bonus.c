/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 05:50:15 by matcardo          #+#    #+#             */
/*   Updated: 2022/09/14 10:07:04 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	handle_error(char *str, int n_exit)
{
	str = ft_strjoin("pipex: ", str);
	perror(str);
	free(str);
	exit(n_exit);
}

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
