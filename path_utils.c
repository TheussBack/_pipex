/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:36:58 by hrobin            #+#    #+#             */
/*   Updated: 2023/04/19 18:47:51 by marvin           ###   ########.fr       */
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
		if (path == NULL)
			return (NULL);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
	}
	return (NULL);
}

char	*add_end_path(char *str, char *cmd, char c)
{
	char	*cpy;
	int	i;
	int	j;

	i = 0;
	j = -1;
	cpy = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(cmd) + 1));
	if (!cpy)
		return (NULL);
	while (str[i])
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = c;
	while (cmd[++j])
		cpy[i++] = cmd[j];
	cpy[i] = '\0';
	return (cpy);
}

char	*verif_path(char *cmd, char **env)
{
	char	**path_tab;
	char	*path;

	path_tab = ft_split(get_path(env), ':');
	path = check_path(path_tab, cmd);
	if (path == NULL)
	{
		free_tab(path_tab);
		free(path);
		return (NULL);
	}
	free_tab(path_tab);
	return (path);
}

char	*get_path(char **env)
{
	int	i;
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=/", 6) == 0)
			return(env[i] + 5);
		i++;
	}
	return (NULL);
}
