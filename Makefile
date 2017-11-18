##
## Makefile for myFTP in /home/theo.huiban/C/PSU/B4/FTP/PSU_2016_myftp
##
## Made by Theo HUIBAN
## Login   <theo.huiban@epitech.net>
##
## Started on  Thu May 11 17:09:25 2017 Theo HUIBAN
## Last update Sun May 21 20:29:35 2017 Theo HUIBAN (theo.huiban@epitech.eu)
##

NAME	=	ftp_service

SRC_DIR	=	srcs

SRC	=	$(SRC_DIR)/main.c \
			$(SRC_DIR)/exec_cmd.c \
			$(SRC_DIR)/handle_client.c \
			$(SRC_DIR)/initserver.c \
			$(SRC_DIR)/server_loop.c \
			$(SRC_DIR)/actowordtab.c \
			$(SRC_DIR)/exit_urg.c \
			$(SRC_DIR)/file_action.c \
			$(SRC_DIR)/info.c \
			$(SRC_DIR)/iptowordtab.c \
			$(SRC_DIR)/login.c \
			$(SRC_DIR)/logout.c \
			$(SRC_DIR)/misc.c \
			$(SRC_DIR)/strtowordtab.c \
			$(SRC_DIR)/trans_param.c \
			$(SRC_DIR)/send_recv.c \
			$(SRC_DIR)/gnl.c
OBJ	=	$(SRC:.c=.o)

INC_DIR	=	includes

CFLAGS	=	-W -Wextra -Wall -I $(INC_DIR)

CC	=	gcc

RM	=	rm -rf

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		@$(CC) -o $(NAME) $(OBJ)
		@echo -e "$(NAME) has been compiled"

%.o: 		%.c
		@echo [OK] $@
		@gcc -o $@ -c $< $(CFLAGS)

clean	:
		@$(RM) $(OBJ)
		@echo -e "The $(NAME) object files have been removed"


fclean :	clean
		@$(RM) $(NAME)
		 @echo -e "The $(NAME) binary file have been removed"


re	: 	fclean all

dbg	:	CFLAGS += -g3
dbg	:	re

install : 	all	
		@sudo cp $(NAME) /usr/bin
		fclean
