/*
** handle_client.c for myFtp in /home/theo.huiban/C/PSU/B4/FTP/PSU_2016_myftp/srcs/
**
** Made by Theo HUIBAN
** Login   <theo.huiban@epitech.eu@epitech.eu>
**
** Started on  Fri May 12 09:39:38 2017 Theo HUIBAN
** Last update Thu May 18 17:21:54 2017 Theo HUIBAN
*/

#include "ftp.h"

char	*my_pwd()
{
  char          *pwd;
  char          cwd[1024];

  getcwd(cwd, sizeof(cwd));
  pwd = strdup(cwd);
  return (pwd);
}

int	handle_client(t_client *c)
{
  printf("Connection from %s:%d\r\n", c->client_ip,
  ntohs(c->s_in_client.sin_port));
  chdir(path);
  c->current = my_pwd();
  c->path = strdup(c->current);
  c->p.i = 0;
  dprintf(c->client_fd, "220 Service ready for new user.\r\n");
  while (1)
    exec_cmd(c, gnl(c->client_fd));
  printf("Deconnection from %s:%d\r\n",
        c->client_ip, ntohs(c->s_in_client.sin_port));
    return (0);
}
