/*
** file_action.c for myFTP in /home/theo.huiban/C/PSU/B4/FTP/PSU_2016_myftp/srcs/
**
** Made by Theo HUIBAN
** Login   <theo.huiban@epitech.eu@epitech.eu>
**
** Started on  Fri May 12 19:10:10 2017 Theo HUIBAN
** Last update Thu May 18 18:45:29 2017 Theo HUIBAN
*/

#include "ftp.h"

void	stor(t_client *c, char *arg)
{
  int fd;
  char buffer[1];

  if (c->p.i == 0)
    dprintf(c->client_fd, "425 Use PORT or PASV first.\r\n");
  else
    {
      if (arg == NULL)
        dprintf(c->client_fd, "501 Select a File\r\n");
      else
        {
          dprintf(c->client_fd, "150 File status okay\r\n");
          fd = open(arg, O_CREAT | O_TRUNC | O_RDWR, 0666);
          if (fd == -1)
          dprintf(c->client_fd, "501 Bad file.\r\n");
          else
          {
            receive(&fd, buffer, c);
            c->p.i = 0;
          }
        }
      }
}

void	retr(t_client *c, char *arg)
{
  int fd;
  char buffer[1];

  if (c->p.i == 0)
    dprintf(c->client_fd, "425 Use PORT or PASV first.\r\n");
  else
    {
      if (arg == NULL)
        dprintf(c->client_fd, "501 Select a File\r\n");
      else
      {
        dprintf(c->client_fd, "150 File status okay\r\n");
        fd = open(arg, O_RDONLY);
        if (fd == -1)
        dprintf(c->client_fd, "501 Bad file.\r\n");
        else
        {
        send1(&fd, buffer, c);
        c->p.i = 0;
      }
    }
  }
}

void	list(t_client *c, char *arg)
{
  struct dirent *dir;
  DIR *inDir;
  char *op;

  if (c->p.i == 0)
    dprintf(c->client_fd, "425 Use PORT or PASV first.\r\n");
  else
  {
    if (arg == NULL)
      op = c->current;
    else
      op = arg;
    if ((inDir = opendir(op)) == NULL)
      dprintf(c->client_fd, "550 Can't list\r\n");
    else
    {
      dprintf(c->client_fd, "150 File status okay\r\n");
      while ((dir = readdir(inDir)) != NULL)
        dprintf(c->p.pasv_cfd, "%s\r\n", dir->d_name);
      close(c->p.pasv_cfd);
      dprintf(c->client_fd, "226 Closing connection (completed)\r\n");
      c->p.i = 0;
    }
  }
}

void	dele(t_client *c, char *arg)
{
  if (remove(arg) == -1)
    dprintf(c->client_fd, "550 File not found.\r\n");
  else
    dprintf(c->client_fd, "250 Requested file action okay, completed.\r\n");
}

void	pwd(t_client *c, char *arg)
{

  int i;

  i = 0;
  arg = arg;
  dprintf(c->client_fd, "257 \"");
  if (strlen(c->current) == strlen(c->path))
  {
    dprintf(c->client_fd, "/");
  }
  else
  {
    i = strlen(c->path);
    while (c->current[i] != '\0')
      dprintf(c->client_fd, "%c", c->current[i++]);
  }
  dprintf(c->client_fd, "\"\r\n");
}
