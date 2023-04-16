/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:36:58 by hrobin            #+#    #+#             */
/*   Updated: 2023/04/14 17:59:18 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_path(char **path_tab, char *cmd)
{
	char *path;
	int	i;

	i = -1;
	while(path_tab[++i])
	{
		path = add_end_path(path_tab[i], cmd, '/');
		if (access(path, F_OK) == 0)
			return (path);
		free_tab(path);
	}
	return (1);
}

char	*add_end_path(char *str, char *av[1], char c)
{
	char	*cpy;
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (str[++i])
		cpy[i] = str[i];
	i++;
	cpy[i] = c;
	while (av[1][++j])
		cpy[i++] = av[1][j];
	cpy[i] = '\0';
	return (cpy);
}

char	*verif_path(char *cmd, char **env)
{
	char	**path_tab;
	char	*path;


	path_tab = ft_split(env, ':');
	path = check_path(path_tab, cmd);
	if (path == 1)
	{
		free_tab(path_tab);
		free(path);
		return (1);
	}
	free_tab(path_tab);
	return (path);
}
