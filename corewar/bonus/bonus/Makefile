##
## makefile for make in tetris
## 
## Made by Romain Pillot
## Login   <romain.pillot@epitech.net>
## 
## Started on  Sat Oct 29 17:09:21 2016 romain pillot
## Last update Wed Apr  5 08:33:47 2017 romain pillot
##

CC	=	gcc

NAME	=	corewar

RM	=	rm -f

SRCS	=	src/main.c			\
		src/cycle_handler.c		\
		src/option.c			\
		src/list.c			\
		src/encoder.c			\
		src/process.c			\
		src/file.c			\
		src/parser.c			\
		src/parser_type.c		\
		src/operation/op_live.c		\
		src/operation/op_ld.c		\
		src/operation/op_st.c		\
		src/operation/op_and.c		\
		src/operation/op_add.c		\
		src/operation/op_sub.c		\
		src/operation/op_or.c		\
		src/operation/op_xor.c		\
		src/operation/op_zjmp.c		\
		src/operation/op_ldi.c		\
		src/operation/op_sti.c		\
		src/operation/op_fork.c		\
		src/operation/op_lld.c		\
		src/operation/op_lldi.c		\
		src/operation/op_lfork.c	\
		src/operation/op_aff.c		\
		src/util/nbr_util.c		\
		src/util/nbr_util_more.c	\
		src/util/out_util.c		\
		src/util/scanner.c		\
		src/util/tab_util.c		\
		src/util/str_util.c		\
		src/util/str_util_more.c	\
		src/util/str_util_plus.c	\
		src/util/util.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	+=	-Iinc -lncurses #-Werror -Wall -Wextra

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
