/*
** ftp.h for myFtp in /home/theo.huiban/C/PSU/B4/FTP/PSU_2016_myftp/includes/
**
** Made by Theo HUIBAN
** Login   <theo.huiban@epitech.eu@epitech.eu>
**
** Started on  Thu May 11 17:23:44 2017 Theo HUIBAN
** Last update Sat May 20 15:44:30 2017 Theo HUIBAN
*/

#ifndef C_MYFTP
# define C_MYFTP

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>


#define MAXCONNECT 42
#define MAXBUFF    4096
#define ANON "Anonymous\r\n"

extern int socket_fd;
extern char *path;

typedef struct s_server
{
    struct protoent *pe;
    struct sockaddr_in s_in;
    int port;
    char *path;
}               t_server;

typedef struct s_pasv
{
  int i;
  struct sockaddr_in s_in;
  struct sockaddr_in cs_in;
  socklen_t   si_in;
  int port;
  struct protoent *pe;
  int pasv_fd;
  int pasv_cfd;
}           t_pasv;

typedef struct s_client
{
  struct sockaddr_in s_in_client;
  socklen_t s_in_size;
  int client_fd;
  char *client_ip;
  int  login;
  char *tmp;
  char *current;
  char *path;
  t_pasv p;
}              t_client;

char **StrToWordTab(char *str);
void exec_cmd(t_client *c, char *cmd);
void error_exit(const char *str);
void initServer(t_server *s, char **av);
int  handle_client(t_client *c);
void server_loop();
void exit_urg();
char **ACToWordTab(char *str);
void help(t_client *c, char *arg);
char **IPToWordTab(char *str);
void cdup(t_client *c, char *arg);
void cwd(t_client *c, char *arg);
void pass(t_client *c, char *arg);
void user(t_client *c, char *arg);
void quit(t_client *c, char *arg);
void noop(t_client *c, char *arg);
char **StrToWordTab(char *str);
void pasv(t_client *c, char *arg);
void port(t_client *c, char *arg);
void stor(t_client *c, char *arg);
void retr(t_client *c, char *arg);
void list(t_client *c, char *arg);
void dele(t_client *c, char *arg);
void pwd(t_client *c, char *arg);
char *my_pwd();
void error_exit(const char *str);
void send1(int *fd, char buffer[1], t_client *c);
void receive(int *fd, char buffer[1], t_client *c);
char *gnl(const int fd);
void ls(t_client *c, char *arg);
void logout(t_client *c, char *arg);

#endif  /* C_MYFTP */
