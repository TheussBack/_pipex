/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:04:58 by hrobin            #+#    #+#             */
/*   Updated: 2023/04/08 14:54:23 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int fd[2]; // Créer un tableau de deux entiers pour stocker les descripteurs de fichiers

  if (pipe(fd) == -1) { // Créer un canal avec pipe()
    perror("pipe");
    exit(1);
  }

  pid_t pid = fork(); // Créer un processus enfant avec fork()

  if (pid == -1) { // Gérer les erreurs de fork()
    perror("fork");
    exit(1);
  } else if (pid == 0) { // Code du processus enfant
    close(fd[1]); // Fermer l'extrémité d'écriture du canal dans le processus enfant

    char buf[256];
    ssize_t n = read(fd[0], buf, sizeof(buf)); // Lire les données du canal dans le processus enfant
    buf[n] = '\0';
    printf("Enfant: lu %ld octets depuis le canal: %s\n", n, buf);

    close(fd[0]); // Fermer l'extrémité de lecture du canal dans le processus enfant
  } else { // Code du processus parent
    close(fd[0]); // Fermer l'extrémité de lecture du canal dans le processus parent

    char *msg = "Salut, enfant !";
    ssize_t n = write(fd[1], msg, strlen(msg)); // Écrire des données dans le canal dans le processus parent
    printf("Parent: écrit %ld octets dans le canal\n", n);

    close(fd[1]); // Fermer l'extrémité d'écriture du canal dans le processus parent
  }

  return 0;
}
