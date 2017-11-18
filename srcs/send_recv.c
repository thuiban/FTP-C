/*
** send_recv.c for myFtp in /home/theo.huiban/C/PSU/B4/FTP/PSU_2016_myftp/srcs/
**
** Made by Theo HUIBAN
** Login   <theo.huiban@epitech.eu@epitech.eu>
**
** Started on  Thu May 18 13:13:43 2017 Theo HUIBAN
** Last update Thu May 18 19:27:21 2017 Theo HUIBAN
*/

#include "ftp.h"

void	send1(int *fd, char buffer[1], t_client *c)
{
  while (read(*fd, buffer, 1) > 0)
    dprintf(c->p.pasv_cfd, "%c", buffer[0]);
  close(*fd);
  close(c->p.pasv_fd);
  dprintf(c->client_fd, "226 Closing connection (completed)\r\n");
}

void	receive(int *fd, char buffer[1], t_client *c)
{
  while (read(c->p.pasv_fd, buffer, 1) > 0)
    dprintf(*fd, "%c", buffer[0]);
  close(*fd);
  close(c->p.pasv_fd);
  dprintf(c->client_fd, "226 Closing connection (completed)\r\n");
}
