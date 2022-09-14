/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 05:03:50 by matcardo          #+#    #+#             */
/*   Updated: 2022/09/14 15:56:57 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include "../libraries/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <sys/wait.h>

void	exec_commands(int argc, char *argv[], char *envp[]);
void	handle_error(char *str, int n_exit);
char	*get_command_path(char *cmd, char *paths[]);
char	**get_paths(char **envp);
char	*get_next_line(int fd);

#endif
