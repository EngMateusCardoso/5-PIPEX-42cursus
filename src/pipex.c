/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 05:03:53 by matcardo          #+#    #+#             */
/*   Updated: 2022/08/07 16:32:04 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <time.h>
int	main()
{
	int fd1[2];
	int fd2[2];
	// fd[0] - read
	// fd[1] - write

	if (pipe(fd1) || pipe(fd2))
		printf("Error opening the pipe!");
	int id = fork();
	if (id == -1)
		printf("Error in fork!");
	if (id == 0)
	{
		//child process
		close(fd1[1]);
		close(fd2[0]);
		int x;
		printf("child reading ...\n");
		if (read(fd1[0], &x, sizeof(x)) == -1)
			printf("Erro on read!");
		printf("received in child %d.\n", x);
		x *= 5;
		printf("child writing... %d.\n", x);
		if (write(fd2[1], &x, sizeof(x)) == -1)
			printf("Erro on write!");
		printf("child wrote %d.\n", x);
		close(fd1[0]);
		close(fd2[1]);
	}
	else
	{
		//Parent process
		close(fd1[0]);
		close(fd2[1]);
		srand(time(NULL));
		int y = rand() % 10;
		printf("parent writing... %d.\n", y);
		if (write(fd1[1], &y, sizeof(y)) == -1)
			printf("Erro on write!");
		printf("parent wrote %d.\n", y);
		printf("parent reading ...\n");
		if (read(fd2[0], &y, sizeof(y)) == -1)
			printf("Erro on write!");
		printf("parent received from child %d.\n", y);
		close(fd1[1]);
		close(fd2[0]);
	}
	
	// int arr[] = {1,2,3,4,5,6,7,8,9};
	// int arrSize = sizeof(arr) / sizeof(int);
	// int id, start, end;
		
	// else
	// {
	// 	id = fork();
	// 	if (id == -1)
	// 		printf("Error in fork 2!");
	// 	if (id == 0)
	// 	{
	// 		start = arrSize / 3;
	// 		end = arrSize / 3 * 2;
	// 	}
	// 	else
	// 	{
	// 		start = arrSize / 3 * 2;
	// 		end = arrSize;
	// 	}
	// }
	// int sum = 0;

  	// for (int i = start; i < end; i++)
	// {
	// 	sum += arr[i];	
	// }
	
	// if (!id)
	// {
	// 	close(fd[0]);
	// 	if (write(fd[1], &sum, sizeof(int)) == -1)
	// 		printf("Erro on write!");
	// 	close(fd[1]);
	// }
	// else
	// {
	// 	int sumFromChild;
	// 	close(fd[1]);
	// 	sum += sumFromChild;
	// 	if (read(fd[0], &sumFromChild, sizeof(int)) == -1)
	// 		printf("Erro on read!");
	// 	sum += sumFromChild;
	// 	close(fd[0]);
	// 	printf("final sum: %d\n", sum);
	// 	wait(NULL);
	// }
	// printf("%d\n", sum);

	return (0);
}
