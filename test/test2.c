/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:48:01 by hrobin            #+#    #+#             */
/*   Updated: 2023/04/11 13:44:56 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>
#include <unistd.h>

int	main()
{
	int fd[2]; //cree un tableau de deux pour les deux retours de pipe [0]read et [1]write;
	if(pipe(fd) == -1) //protection
		printf("error accord with the pipe\n");
	int id = fork(); //creation d'un processus enfant
	if (id == -1) //prottecion encore;   
		return (4);
	if (id == 0) // on s'adresse au processus enfant;
	{
		close(fd[0]); // on utilise la cle de fd qui ecrit donc on ferme celle qui lit
		int x;
		printf("inpu a number: ");
		scanf("%d", &x); //demander un nomvbre
		if (write(fd[1], &x, sizeof(int)) == -1) //on ecrit dans fd[1] le nombre renvoye par l'utilisateur plus protection
			return (2);
		close (fd[1]); //on ferme pus besoin
	}
	else // on s'adresse au processus parent;
	{
		close (fd[1]); // pas besoin d'ecrire
		int y;
		if (read(fd[0], &y, sizeof(int)) == -1) //on uttilise read donc fd[0] + la taille de ce que on veutt read
			return (3);
		y = y * 10; // si je veux y faire un changement de la valeur recue
		close (fd[0]); // ferme le fd
		printf("got frome child process %d\n", y);
	}
	return (0);
}
