/*
** login.c for myFtp in /home/theo.huiban/C/PSU/B4/FTP/PSU_2016_myftp/srcs/
**
** Made by Theo HUIBAN
** Login   <theo.huiban@epitech.eu@epitech.eu>
**
** Started on  Fri May 12 16:58:33 2017 Theo HUIBAN
** Last update Sun May 21 15:58:47 2017 Theo HUIBAN
*/

#include "ftp.h"

void	cdup(t_client *c, char *arg)
{
  arg = arg;
  if (strcmp(c->current, c->path) != 0)
    {
      chdir("..");
      c->current = my_pwd();
    }
  dprintf(c->client_fd, "200 Command okay.\r\n");
}

void	cwd(t_client *c, char *arg)
{
  if (arg == NULL || arg[0] == '/' || strncmp("..", arg, 2) == 0)
  {
    dprintf(c->client_fd, "550 Failed to change directory.\r\n");
  }
  else
  {
    if (chdir(arg) == -1)
      dprintf(c->client_fd, "550 Failed to change directory.\r\n");
    else
    {
      dprintf(c->client_fd, "250 Requested file action okay, completed.\r\n");
      c->current = my_pwd();
    }
  }
}

void	pass(t_client *c, char *arg)
{
  arg = arg;
  if (strncmp(ANON, c->tmp, strlen(ANON) - 2) == 0)
  {
    c->login = 1;
    free(c->tmp);
    dprintf(c->client_fd, "230 User logged in, proceed.\r\n");
  }
  else
   {
     free(c->tmp);
     dprintf(c->client_fd, "530 Login incorrect.\r\n");
  }
}

void	user(t_client *c, char *arg)
 {
   if (arg == NULL)
   {
     dprintf(c->client_fd, "530 Permission denied.\r\n");
   }
    else
    {
      if (c->login == 1)
      {
        dprintf(c->client_fd, "530 Can't change from guest user.\r\n");
      }
      else
      {
        c->tmp = strdup(arg);
        dprintf(c->client_fd, "331 Please specify the password.\r\n");
      }
    }
}
