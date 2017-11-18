/*
** exec_cmd.c for myFtp in /home/theo.huiban/C/PSU/B4/FTP/PSU_2016_myftp/srcs/
**
** Made by Theo HUIBAN
** Login   <theo.huiban@epitech.eu@epitech.eu>
**
** Started on  Fri May 12 10:56:21 2017 Theo HUIBAN
** Last update Sun May 21 16:11:20 2017 Theo HUIBAN
*/

#include "ftp.h"
#include "g_cmd.h"

void	haveR(char *str)
{
  int  i;

  i = 0;
  if (str != NULL)
    {
      while (str[i] != '\0')
        {
          if (str[i] == '\r')
          {
              str[i] = '\0';
              break;
          }
            i++;
        }
    }
}

void	do_cmd(t_client *c, char *arg, int index)
{
  if (c->login == 0)
  {
    if (strncmp(g_cmd[index], "USER", 4) == 0 ||
        strncmp(g_cmd[index], "PASS", 4) == 0 ||
        strncmp(g_cmd[index], "QUIT", 4) == 0)
        g_func_cmd[index](c, arg);
    else
      dprintf(c->client_fd, "530 Please login with USER and PASS.\r\n");
  }
  else
  {
    if (index > 17)
      dprintf(c->client_fd, "500 Unknown command.\r\n");
    else
    {
      haveR(arg);
      g_func_cmd[index](c, arg);
    }
  }
}

void	exec_cmd(t_client *c, char *buff)
{
  char  **cmd;
  int   i = 1;

  cmd = StrToWordTab(strndup(buff, strlen(buff)));
  while (g_cmd[i] != NULL)
      {
        if (strncmp(g_cmd[i], cmd[0], strlen(g_cmd[i])) == 0)
        {
          do_cmd(c, cmd[1], i);
          break;
        }
        i++;
    }
    if (g_cmd[i] == NULL)
    {
      if (c->login == 0)
        dprintf(c->client_fd, "530 Please login with USER and PASS.\r\n");
      else
        dprintf(c->client_fd, "500 Unknown command.\r\n");
    }
  free(cmd);
}
