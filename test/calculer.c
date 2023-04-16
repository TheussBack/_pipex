/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:47:35 by hrobin            #+#    #+#             */
/*   Updated: 2023/04/11 14:22:44 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int	main()
{
	int	arr[] = { 1, 2, 3, 4, 1, 2 };
	int	fd[2];
	int	id;
	if (pipe(fd) == -1)
		return (1);
	int i = 0;
	int sum;
	id = fork();
	if (id == 0)
	{
		while (i <= 3)
		{
			sum += arr[i];
			i++;
		}
		printf("sum1 = %d\n", sum);
	}
	else
		{
			int p;
			wait(&p);
			while (i > 3 && i <= 6)
			{
				sum += arr[i];
				i++;
			}
			printf("sum2 = %d\n", sum);
		}
		return (0);
}
