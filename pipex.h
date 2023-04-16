/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:54:46 by hrobin            #+#    #+#             */
/*   Updated: 2023/04/14 17:36:47 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>

// main //
void	do_prcs(char **av, char **env, pid_t id, int fd[2]);
void	child_prcs(char **av, char **env, char **cmds, int fd[2]);

//utils//
char	*get_path(char **env);
int	ft_strncmp(char *s1, char *s2, size_t n);

//Path_utils//
char	*check_path(char **path_tab, char *cmd);
char	*add_end_path(char *str, char *av[1], char c);

//free//
void	free_tab(char **tab);

#endif
