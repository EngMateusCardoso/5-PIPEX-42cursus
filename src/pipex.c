/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 05:03:53 by matcardo          #+#    #+#             */
/*   Updated: 2022/08/07 18:45:12 by matcardo         ###   ########.fr       */
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
		execlp("ls", "ls", "-l", NULL);
		printf("not printed!");
	}
	else
	{
		//Parent process
		wait(NULL);
		printf("success!");
	}

	return (0);
}
