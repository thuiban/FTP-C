/*
** misc.c for myFTP in /home/theo.huiban/C/PSU/B4/FTP/PSU_2016_myftp/srcs/
**
** Made by Theo HUIBAN
** Login   <theo.huiban@epitech.eu@epitech.eu>
**
** Started on  Fri May 12 17:54:50 2017 Theo HUIBAN
** Last update Thu May 18 13:48:53 2017 Theo HUIBAN
*/

#include "ftp.h"

void	noop(t_client *c, char *arg)
{
  arg = arg;
  dprintf(c->client_fd, "200 Command okay.\r\n");
}
