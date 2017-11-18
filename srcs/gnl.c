/*
** gnl.c for myftp in /home/theo.huiban/C/PSU/B4/FTP/PSU_2016_myftp/srcs/
**
** Made by Theo HUIBAN
** Login   <theo.huiban@epitech.eu@epitech.eu>
**
** Started on  Thu May 18 17:17:33 2017 Theo HUIBAN
** Last update Thu May 18 18:50:12 2017 Theo HUIBAN
*/

#include "ftp.h"

void	ls(t_client *c, char *arg)
{
  struct dirent *dir;
  DIR *inDir;
  char *op;

if (arg == NULL)
    op = c->current;
else
    op = arg;
if ((inDir = opendir(op)) == NULL)
    dprintf(c->client_fd, "550 Can't list\r\n");
else
  {
    while ((dir = readdir(inDir)) != NULL)
      dprintf(c->client_fd, "%s\r\n", dir->d_name);
    dprintf(c->client_fd, "200 Command OK\r\n");
    }
}

char	*char_char(char *str, char c)
{
  char  *new;
  int   i;

  i = 0;
  if (str == NULL)
    {
      if ((new = malloc(2 * sizeof(*new))) == NULL)
        return (NULL);
      new[0] = c;
      new[1] = '\0';
    }
  else
    {
      if ((new = malloc((strlen(str) + 2) * sizeof(*new))) == NULL)
        return (NULL);
      while (str[i])
        {
          new[i] = str[i];
          ++i;
        }
      new[i++] = c;
      new[i] = '\0';
    }
  free(str);
  return (new);
}

char	*gnl(const int fd)
{
  char  a;
  char  *ret;

  ret = NULL;
  while ((read(fd, &a, 1)) > 0)
    {
      if (a == '\n' || a == '\0')
        {
          if (ret == NULL)
            if ((ret = char_char(ret, '\0')) == NULL)
              return (NULL);
          return (ret);
        }
      if ((ret = char_char(ret, a)) == NULL)
        return (NULL);
    }
  return (ret);
}
