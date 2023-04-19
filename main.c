/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:23:47 by hrobin            #+#    #+#             */
/*   Updated: 2023/04/19 18:15:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_prcs(char **av, char **env, char **cmds, int fd[2])
{
	char *path_ok;
	int	infile;

	infile = open(av[1], O_RDONLY);
	path_ok = verif_path(cmds[0], env);
	if (infile == -1)
	{
		perror("OPEN AV[1]");
		exit(EXIT_FAILURE);
	}
	if (path_ok == NULL)
		wrong_cmds(cmds);
	if (dup2(infile, STDIN_FILENO) < 0)
		exit(EXIT_FAILURE);
	if (dup2(fd[1], STDOUT_FILENO) < 0)
		exit(EXIT_FAILURE);
	close (fd[0]);
	execve(path_ok, cmds, env);
	close (fd[1]);
	free(path_ok);
	close(infile);
}

void	parent_prcs(char **av, char **env, char **cmds, int fd[2])
{
	int	outfile;
	char *path_ok;

	outfile = open(av[4], O_RDONLY);
	path_ok = verif_path(cmds[0], env);
	if (outfile == -1)
		exit(EXIT_FAILURE);
	if (path_ok == NULL)
		wrong_cmds(cmds);
	if (dup2(fd[0], STDIN_FILENO) < 0)
		exit(EXIT_FAILURE);
	if (dup2(outfile, STDOUT_FILENO) < 0)
		exit(EXIT_FAILURE);
	close(fd[1]);
	execve(path_ok, cmds, env);
	close(fd[0]);
	free(path_ok);
	close(outfile);

}

void	do_prcs(char **av, char **env, pid_t id, int fd[2])
{
	char **cmds;

	id = fork();
	if (id == -1)
		exit (EXIT_FAILURE);
	if (id == 0)
	{
		cmds = ft_split(av[2], ' ');
		if (!cmds)
			wrong_cmds(cmds);
		child_prcs(av, env, cmds, fd);
	}
	else
	{
		cmds = ft_split(av[3], ' ');
		if (!cmds)
			wrong_cmds(cmds);
		waitpid(id, NULL, WNOHANG);
		parent_prcs(av, env, cmds, fd);
	}
	free(cmds);
}

int	main(int ac, char **av, char **env)
{
	pid_t	id;
	id = 0;
	int	fd[2];

	if (ac < 5)
		return (1);
	if (pipe(fd) == -1)
	{
		perror("error occured with the pipe");
		exit (EXIT_FAILURE);
	}
	do_prcs(av, env, id, fd);
	return(0);
}
