/*
** init_Server.c for myFtp in /home/theo.huiban/C/PSU/B4/FTP/PSU_2016_myftp/srcs/
**
** Made by Theo HUIBAN
** Login   <theo.huiban@epitech.eu@epitech.eu>
**
** Started on  Fri May 12 09:38:08 2017 Theo HUIBAN
** Last update Thu May 18 13:43:55 2017 Theo HUIBAN
*/

#include "ftp.h"
char *path;

void	initServer(t_server *s, char **av)
{
    s->port = atoi(av[1]);
    s->s_in.sin_family = AF_INET;
    s->s_in.sin_port = htons(s->port);
    s->s_in.sin_addr.s_addr = INADDR_ANY;
    s->pe = getprotobyname("TCP");
    if (!s->pe)
        error_exit("getprotobyname() fail.");
    path = av[2];
}
