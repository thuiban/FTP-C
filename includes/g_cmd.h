/*
** g_cmd.h for myFtp in /home/theo.huiban/C/PSU/B4/FTP/PSU_2016_myftp/includes/
**
** Made by Theo HUIBAN
** Login   <theo.huiban@epitech.eu@epitech.eu>
**
** Started on  Fri May 12 11:00:02 2017 Theo HUIBAN
** Last update Sat May 20 15:44:03 2017 Theo HUIBAN
*/

#ifndef C_G_CMD
# define C_G_CMD

#include "ftp.h"

#define NBR_FUNC 18

static char *(g_cmd[NBR_FUNC]) =
{
  NULL,
  "USER",
  "PASS",
  "QUIT",
  "CWD",
  "CDUP",
  "PORT",
  "PASV",
  "STOR",
  "RETR",
  "LIST",
  "DELE",
  "PWD",
  "NOOP",
  "HELP",
  "LS",
  "LOGOUT",
  NULL
};

static void (*g_func_cmd[NBR_FUNC])(t_client *c, char *arg) =
{
  NULL,
  &user,
  &pass,
  &quit,
  &cwd,
  &cdup,
  &port,
  &pasv,
  &stor,
  &retr,
  &list,
  &dele,
  &pwd,
  &noop,
  &help,
  &ls,
  &logout,
  NULL
};

#endif /* C_G_CMD  */
