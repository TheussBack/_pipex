/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:35:14 by hrobin            #+#    #+#             */
/*   Updated: 2023/04/19 01:34:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wrong_cmds(char **cmds)
{
	int len;

	len = ft_strlen(cmds[0]);
	write(STDERR_FILENO, "command not found: ", 19);
	write(STDERR_FILENO, cmds[0], len);
	write(STDERR_FILENO, "\n", 1);
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
