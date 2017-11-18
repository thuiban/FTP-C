/*
** logout.c for myFtp in /home/theo.huiban/C/PSU/B4/FTP/PSU_2016_myftp/srcs/
**
** Made by Theo HUIBAN
** Login   <theo.huiban@epitech.eu@epitech.eu>
**
** Started on  Fri May 12 17:44:56 2017 Theo HUIBAN
** Last update Sat May 20 17:02:00 2017 Theo HUIBAN
*/

#include "ftp.h"

void	quit(t_client *c, char *arg)
{
  arg = arg;
  dprintf(c->client_fd, "221 %s\r\n",
          "Bye !");
  printf("Deconnection from %s:%d\r\n", c->client_ip,
	 ntohs(c->s_in_client.sin_port));
  close(c->client_fd);
_exit(0);
}

void	logout(t_client *c, char *arg)
{
  arg = arg;
  dprintf(c->client_fd, "232 User logout\r\n");
  c->login = 0;
}
