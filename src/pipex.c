/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 05:03:53 by matcardo          #+#    #+#             */
/*   Updated: 2022/08/07 01:22:20 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main()
{
	int id;
	int fd[2];
	// fd[0] - read
	// fd[1] - wirte
	if (pipe(fd))
		printf("Error opening the pipe!");
	id = fork();
	if (id == -1)
		printf("Error in fork!");
	if (id == 0)
	{
		close(fd[0]);
		int x;
		printf("Input a number: ");
		scanf("%d", &x);
		if (write(fd[1], &x, sizeof(int)) == -1)
			printf("Erro on write!");
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		int y;
		if (read(fd[0], &y, sizeof(int)) == -1)
			printf("Erro on read!");
		close(fd[0]);
		printf("Got from  child process %d\n", y);
	}
	return (0);
}
