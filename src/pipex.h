/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 05:03:50 by matcardo          #+#    #+#             */
/*   Updated: 2022/07/26 22:15:16 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX
# define PIPEX

# include "../libraries/libft/libft.h"
// for malloc, free and exit.
# include <stdlib.h>
// for close, read, write, access, dup, dup2, execve, fork, pipe and unlink.
# include <unistd.h>
// for open.
# include <fcntl.h>
// for perror and strerror.
#include <stdio.h>
// for wait and waitpid.
#include <sys/wait.h>

void fct();

#endif
