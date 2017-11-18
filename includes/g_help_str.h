/*
** g_help_str.h for myFtp in /home/theo.huiban/C/PSU/B4/FTP/PSU_2016_myftp/includes/
**
** Made by Theo HUIBAN
** Login   <theo.huiban@epitech.eu@epitech.eu>
**
** Started on  Wed May 17 16:42:17 2017 Theo HUIBAN
** Last update Sat May 20 15:43:38 2017 Theo HUIBAN
*/

#ifndef C_G_HELP
#define C_G_HELP

#include "ftp.h"

#define NBR_FUN 18

static char *(g_cmd_help[NBR_FUN]) =
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

static char *g_help_str[NBR_FUN] =
{
  NULL,
  "USER : Specify user for authentication",
  "PASS : Specify password for authentication",
  "QUIT : Disconnection",
  "CWD  : Change working directory",
  "CDUP : Change working directory to parent directory",
  "PORT : Enable \"active\" mode for data transfer",
  "PASV : Enable \"passive\" mode for data transfer",
  "STOR : Upload file from client to server",
  "RETR : Download file from server to client",
  "LIST : List files in the current working directory",
  "DELE : Delete file on the server",
  "PWD  : Print working directory",
  "NOOP : Do nothing",
  "HELP : List available commadns",
  "LS   : Print files and folders in working directory",
  "LOGOUT : Disconnection of current session",
  NULL
};

#endif /* C_G_HELP */
