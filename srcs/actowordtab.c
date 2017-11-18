/*
** actowordtab.c for myFtp in /home/theo.huiban/C/PSU/B4/FTP/PSU_2016_myftp/srcs/
**
** Made by Theo HUIBAN
** Login   <theo.huiban@epitech.eu@epitech.eu>
**
** Started on  Fri May 12 11:17:10 2017 Theo HUIBAN
** Last update Thu May 18 13:53:47 2017 Theo HUIBAN
*/

#include "ftp.h"

int	taiAC(char *str)
{
  int           i;
  int           lol;

  i = 0;
  lol = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ',' &&
          str[i + 1] != ','
          && str[i + 1] != '\0')
        lol++;
      i++;
    }
  return (lol + 1);
}

char	**ACToWordTab(char *str)
{
  char          **stt;
  int           i;
  int           tail;

  tail = taiAC(str);
  i = 0;
  if ((stt = malloc((tail + 1) * sizeof(*stt))) == NULL)
    return (NULL);
  stt[taiAC(str)] = NULL;
  while (i < tail && *str != 0)
    {
      while (*str != 0 && *str == ',')
        str++;
      stt[i] = str;
      while (*str != '\0' && *str != ',')
        str++;
      *str = '\0';
      str++;
      while (*str != '\0' && *str == ',')
	     str++;
      i++;
    }
  return (stt);
}
