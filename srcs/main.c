/*
** main.c for myFtp in /home/theo.huiban/C/PSU/B4/FTP/PSU_2016_myftp/srcs/
**
** Made by Theo HUIBAN
** Login   <theo.huiban@epitech.eu@epitech.eu>
**
** Started on  Thu May 11 17:25:41 2017 Theo HUIBAN
** Last update Thu May 18 13:53:31 2017 Theo HUIBAN
*/

#include "ftp.h"

int	socket_fd;

void	error_exit(const char *str)
{
    printf("[Error]: %s\n", str);
    exit(1);
}

void	usage(char *bin)
{
  printf("USAGE: %s port path\n", bin);
  exit(1);
}

int	main(int ac, char **av)
{
  t_server s;

   (ac != 3) ? usage(av[0]): 0;
  initServer(&s, av);
  socket_fd = socket(AF_INET, SOCK_STREAM, s.pe->p_proto);
  if (socket_fd == -1)
        error_exit("socket() fail.");
    if (bind(socket_fd, (const struct sockaddr *) &s.s_in,
	     sizeof(s.s_in)) == -1)
     {
       close(socket_fd);
       error_exit("bind() fail.");
    }
    if (listen(socket_fd, 42) == -1)
    {
        (close(socket_fd) == -1) ? error_exit("close() fail."): 0;
        error_exit("listen() fail.");
    }
    signal(SIGINT, exit_urg);
    signal(SIGPIPE, exit_urg);
    while (1)
      server_loop(&s);
    if (close(socket_fd) == -1)
        error_exit("close() fail.");
  return (0);
}
