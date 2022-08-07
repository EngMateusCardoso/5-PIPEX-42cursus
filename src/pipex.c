/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 05:03:53 by matcardo          #+#    #+#             */
/*   Updated: 2022/08/07 04:20:45 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int arrSize = sizeof(arr) / sizeof(int);
	int id, start, end;
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
		start = 0;
		end = arrSize / 2;
	}
	else
	{
		start = arrSize / 2;
		end = arrSize;
	}
	int sum = 0;

  	for (int i = start; i < end; i++)
	{
		sum += arr[i];	
	}
	
	if (!id)
	{
		close(fd[0]);
		if (write(fd[1], &sum, sizeof(int)) == -1)
			printf("Erro on write!");
		close(fd[1]);
	}
	else
	{
		int sumFromChild;
		close(fd[1]);
		if (read(fd[0], &sumFromChild, sizeof(int)) == -1)
			printf("Erro on read!");
		close(fd[0]);
		printf("final sum: %d\n", sum + sumFromChild);
		wait(NULL);
	}
	printf("%d\n", sum);

	return (0);
}
