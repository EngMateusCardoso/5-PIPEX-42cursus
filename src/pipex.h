/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 05:03:50 by matcardo          #+#    #+#             */
/*   Updated: 2022/09/13 14:40:14 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libraries/libft/libft.h"
// for malloc, free and exit.
# include <stdlib.h>
// for close, read, write, access, dup, dup2, execve, fork, pipe and unlink.
# include <unistd.h>
// for open.
# include <fcntl.h>
// for perror and strerror.
# include <stdio.h>
# include <errno.h>
// for wait and waitpid.
# include <sys/wait.h>

void	exec_commands(char *argv[], char *envp[]);
void	handle_error(const char *str, int error, int n_exit);

#endif
