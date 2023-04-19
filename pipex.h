/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:54:46 by hrobin            #+#    #+#             */
/*   Updated: 2023/04/19 17:40:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>

// main //
void	do_prcs(char **av, char **env, pid_t id, int fd[2]);
void	child_prcs(char **av, char **env, char **cmds, int fd[2]);

//utils//
int	ft_strncmp(char *s1, char *s2, size_t n);
int	ft_strlen(char *str);

//Path_utils//
char	*check_path(char **path_tab, char *cmd);
char	*add_end_path(char *str, char *av, char c);
char	*verif_path(char *cmd, char **env);
char	*get_path(char **env);

//free//
void	free_tab(char **tab);
void	wrong_cmds(char **cmds);

//SPLIT//
char	**ft_split(char const *s, char c);

#endif
