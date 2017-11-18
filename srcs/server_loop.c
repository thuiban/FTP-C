/*
** server_loop.c for myFtp in /home/theo.huiban/C/PSU/B4/FTP/PSU_2016_myftp/srcs/
**
** Made by Theo HUIBAN
** Login   <theo.huiban@epitech.eu@epitech.eu>
**
** Started on  Fri May 12 09:41:37 2017 Theo HUIBAN
** Last update Thu May 18 13:50:27 2017 Theo HUIBAN
*/

#include "ftp.h"

extern int socket_fd;

void	server_loop()
{
    t_client c;
    pid_t pid;

    c.s_in_size = sizeof(c.s_in_client);
    c.client_fd = accept(socket_fd,
      (struct sockaddr *) &c.s_in_client, &c.s_in_size);
    if (c.client_fd == -1) {
        if (close(socket_fd) == -1)
            error_exit("close() fail.");
        error_exit("accept() fail.");
    }
    pid = fork();
    if (pid == 0) {
        c.client_ip = inet_ntoa(c.s_in_client.sin_addr);
        handle_client(&c);
    } else {
        if (close(c.client_fd) == -1)
            error_exit("close() fail.");
    }
}
