/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 05:03:53 by matcardo          #+#    #+#             */
/*   Updated: 2022/08/06 22:27:48 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main()
{
	int id = fork();
	int id2 = -1;
	int id3 = -1;
	id2 = fork();
	id3 = fork();
	
	printf("id1: %d, id2: %d, id3: %d,Current (getpid): %d, parent (getppid): %d\n", id, id2, id3, getpid(), getppid());
	return (0);
}
