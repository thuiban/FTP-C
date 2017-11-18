/*
** exit_urg.c for myftp in /home/theo.huiban/C/PSU/B4/FTP/PSU_2016_myftp/srcs/
**
** Made by Theo HUIBAN
** Login   <theo.huiban@epitech.eu@epitech.eu>
**
** Started on  Fri May 12 09:40:26 2017 Theo HUIBAN
** Last update Thu May 18 13:38:40 2017 Theo HUIBAN
*/

#include "ftp.h"

void	exit_urg()
{
    close(socket_fd);
    exit(0);
}
