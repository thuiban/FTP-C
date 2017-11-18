/*
** info.c for myFtp in /home/theo.huiban/C/PSU/B4/FTP/PSU_2016_myftp/srcs/
**
** Made by Theo HUIBAN
** Login   <theo.huiban@epitech.eu@epitech.eu>
**
** Started on  Fri May 12 17:52:05 2017 Theo HUIBAN
** Last update Sat May 20 17:00:22 2017 Theo HUIBAN
*/

#include "ftp.h"
#include "g_help_str.h"

void	help(t_client *c, char *arg)
{
  int i;

  i = 1;
  if (arg == NULL)
    {
      dprintf(c->client_fd, "214 The following commands are recognized.\r\n");
      dprintf(c->client_fd, " CDUP CWD DELE LIST NOOP PASS\r\n");
      dprintf(c->client_fd, " PASV PORT PWD QUIT RETR STOR USER\r\n");
      dprintf(c->client_fd, " LS\r\n");
      dprintf(c->client_fd, "214 Help OK.\r\n");
    }
    else
    {
    while (g_cmd_help[i] != NULL)
    {
      if (strncmp(g_cmd_help[i], arg, strlen(g_cmd_help[i])) == 0)
      {
        dprintf(c->client_fd, "214 %s\r\n", g_help_str[i]);
        break;
      }
      i++;
    }
    if (g_cmd_help[i] == NULL)
      dprintf(c->client_fd, "214 Command not implemented\r\n");
    }
}
