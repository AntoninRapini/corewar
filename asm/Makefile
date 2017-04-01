##
## Makefile for my_ls in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_ls
## 
## Made by Antonin Rapini
## Login   <antonin.rapini@epitech.net>
## 
## Started on  Tue Nov 29 08:50:17 2016 Antonin Rapini
## Last update Sun Apr  2 08:10:59 2017 Antonin Rapini
##

CFLAGS	+= -Wall -Werror -Wextra
CFLAGS 	+= -I include

SRC	=	utils/my_open_champion.c	\
		utils/my_cor_utils.c		\
		utils/my_memset.c		\
		utils/my_strlen.c		\
		utils/my_strcmp.c		\
		utils/get_next_line.c		\
		utils/my_strncmp.c		\
		utils/my_getfile.c		\
		utils/my_wordtab_utils.c	\
		utils/my_putstr.c		\
		utils/my_putchar.c		\
		utils/my_strndup.c		\
		utils/my_str_to_params.c	\
		utils/my_getnbr.c		\
		utils/my_miniprintf.c		\
		utils/my_put_nbr.c		\
		utils/my_line_iscode.c		\
		utils/my_labellist_utils.c	\
		utils/my_instlist_utils.c	\
		sources/my_get_champion.c	\
		sources/my_get_header.c		\
		sources/my_get_code.c		\
		sources/my_add_label.c		\
		sources/my_add_instruction.c	\
		sources/my_check_instruction.c	\
		sources/my_get_paramtype.c	\
		sources/my_clear_param.c	\
		sources/my_create_corfile.c	\
		sources/my_write_header.c	\
		sources/my_write_instructions.c	\
		sources/my_write_value.c	\
		sources/my_write_label.c	\
		sources/my_check_label_calls.c	\
		asm.c

OBJ	=	$(SRC:.c=.o)

NAME	= 	asm

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
