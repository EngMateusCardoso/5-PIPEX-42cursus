/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 05:03:53 by matcardo          #+#    #+#             */
/*   Updated: 2022/08/07 19:09:12 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <time.h>
int	main()
{
	int id = fork();
	if (id == -1)
		printf("Error in fork!");
	if (id == 0)
	{
		//child process
		int err = execlp("lgs", "ls", "-l", NULL);
		if (err == -1)
			printf("Could not find the program to execute!\n");
	}
	else
	{
		//Parent process
		int wstatus;
		wait(&wstatus);
		if(WIFEXITED(wstatus))
		{
			int statusCode = WEXITSTATUS(wstatus);
			if (statusCode == 0)
				printf("success!\n");
			else
				printf("failure with status code %d!\n", statusCode);
		}
	}

	return (0);
}
