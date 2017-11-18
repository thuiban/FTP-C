/*
** StrToWordTab.c for myFtp in /home/theo.huiban/C/PSU/B4/FTP/PSU_2016_myftp/srcs/
**
** Made by Theo HUIBAN
** Login   <theo.huiban@epitech.eu@epitech.eu>
**
** Started on  Fri May 12 11:17:10 2017 Theo HUIBAN
** Last update Thu May 18 16:26:21 2017 Theo HUIBAN
*/

#include "ftp.h"

int	tai(char *str)
{
  int           i;
  int           lol;

  i = 0;
  lol = 0;
  while (str[i] != '\0')
    {
      if ((str[i] == ' ' || str[i] == '\t') &&
          (str[i + 1] != ' ' && str[i + 1] != '\t')
          && str[i + 1] != '\0')
        lol++;
      i++;
    }
  return (lol + 1);
}

char	**StrToWordTab(char *str)
{
  char          **stt;
  int           i;
  int           tail;

  tail = tai(str);
  i = 0;
  if ((stt = malloc((tail + 1) * sizeof(*stt))) == NULL)
    return (NULL);
  stt[tai(str)] = NULL;
  while (i < tail && *str != 0)
    {
      while (*str != 0 && (*str == ' ' || *str == '\t'))
        str++;
      stt[i] = str;
      while (*str != '\0' && (*str != ' ' && *str != '\t'))
        str++;
      *str = '\0';
      str++;
      while (*str != '\0' && (*str == ' ' || *str == '\t'))
	     str++;
      i++;
    }
  return (stt);
}
