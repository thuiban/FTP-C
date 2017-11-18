/*
** trans_param.c for myFtp in /home/theo.huiban/C/PSU/B4/FTP/PSU_2016_myftp/srcs/
**
** Made by Theo HUIBAN
** Login   <theo.huiban@epitech.eu@epitech.eu>
**
** Started on  Fri May 12 17:51:25 2017 Theo HUIBAN
** Last update Sat May 20 15:34:34 2017 Theo HUIBAN
*/

#include "ftp.h"

void	initPasvStruct(t_pasv *p)
{
  p->pe = getprotobyname("TCP");
  p->s_in.sin_family = AF_INET;
  p->s_in.sin_port = 0;
  p->s_in.sin_addr.s_addr = INADDR_ANY;
  p->si_in = sizeof(p->s_in);
}

void	pasv(t_client *c, char *arg)
{
  socklen_t tmp;
  char **ip;

  arg = arg;
  initPasvStruct(&c->p);
  ip = IPToWordTab(c->client_ip);
  tmp = sizeof(c->p.cs_in);
  c->p.pasv_fd = socket(AF_INET, SOCK_STREAM, c->p.pe->p_proto);
  bind(c->p.pasv_fd, (const struct sockaddr *)&c->p.s_in, c->p.si_in);
  listen(c->p.pasv_fd, 1);
  c->p.port = ntohs(c->p.s_in.sin_port);
  dprintf(c->client_fd, " 227 Entering Passive Mode (%s,%s,%s,%s,%d,%d).\r\n",
          ip[0], ip[1], ip[2], ip[3], c->p.port / 256, c->p.port % 256);
  c->p.pasv_cfd = accept(c->p.pasv_fd, (struct sockaddr *)&c->p.cs_in, &tmp);
  c->p.i = 1;
}

int	initActive(t_pasv *pasv, char *ip, char *port)
{
  int ret;

  pasv->pe = getprotobyname("TCP");
  pasv->pasv_cfd = socket(AF_INET, SOCK_STREAM, pasv->pe->p_proto);
  pasv->cs_in.sin_family = AF_INET;
  pasv->cs_in.sin_port = htons(atoi(port));
  pasv->cs_in.sin_addr.s_addr = inet_addr(ip);
  ret = connect(pasv->pasv_cfd,
		(const struct sockaddr *)&pasv->cs_in,
		sizeof(pasv->cs_in));
  return (ret);
}

void	port(t_client *c, char *arg)
{
  char **ac;
  char newip[32];
  char port[12];

  ac = ACToWordTab(strdup(arg));
  sprintf(newip, "%s.%s.%s.%s",
  ac[0], ac[1], ac[2], ac[3]);
  sprintf(port, "%d", atoi(ac[4]) * 256 + atoi(ac[5]));
  if (initActive(&c->p, newip, port) == 0)
  {
    dprintf(c->client_fd, "200 Command okay.\r\n");
    c->p.i = 1;
  }
  else
    dprintf(c->client_fd, "500 Illegal PORT command.\r\n");
}
