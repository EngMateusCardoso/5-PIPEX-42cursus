/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 05:03:53 by matcardo          #+#    #+#             */
/*   Updated: 2022/09/13 17:22:50 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_error(const char *str, int error, int n_exit)
{
	errno = error;
	perror(str);
	exit(n_exit);
}

int	main(int argc, char *argv[], char *envp[])
{
	if (argc != 5)
		handle_error("Error", EINVAL, EXIT_FAILURE);
	else
		exec_commands(argv, envp);
	return (0);
}
