/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:35:14 by hrobin            #+#    #+#             */
/*   Updated: 2023/04/21 14:41:53 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wrong_cmds(char **cmds)
{
	if (cmds[0])
	{
		write(STDERR_FILENO, "command not found: ", 19);
		write(STDERR_FILENO, cmds[0], ft_strlen(cmds[0]));
		write(STDERR_FILENO, "\n", 1);
	}
	free_tab(cmds);
	exit(EXIT_FAILURE);
}

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	if (tab)
		free(tab);
}
