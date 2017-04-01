/*
** my_header.h for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon Mar 27 15:02:04 2017 Antonin Rapini
** Last update Fri Mar 31 19:20:33 2017 Antonin Rapini
*/

#ifndef MY_ASM_H_
# define MY_ASM_H_

# define IDX_MOD 512
# define MAX_ARGS_NUMBER 4

# define COMMENT_CHAR '#'
# define LABEL_CHAR ':'
# define DIRECT_CHAR '%'
# define SEPARATOR_CHAR ','

# define NAME_CMD_STRING ".name"
# define COMMENT_CMD_STRING ".comment"

# define COREWAR_EXEC_MAGIC 0xea83f3
# define COREWAR_EXEC_MAGIC_STR "\xea\x83\xf3"
# define PROG_NAME_LENGTH 128
# define COMMENT_LENGTH 2048

# define PROG_LEN_LENGTH 8
# define HEXA_CHARSET "0123456789abcdef"
# define REG_NUMBER 16

# define IND_SIZE 2
# define DIR_SIZE 4
# define REG_SIZE DIR_SIZE

# define T_REG 1
# define T_DIR 2
# define T_IND 4

# define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"

typedef struct	s_param
{
  char		*param;
  char		type;
  int		size;
  int		islabel;
}		t_param;

typedef struct	s_instruct
{
  char		*name;
  t_param	*params;
  int		code;
  int		codingbyte;
  int		pos;
}		t_instruct;

typedef struct	s_label
{
  char		*name;
  int		pos;
}		t_label;

typedef struct		s_labellist
{
  t_label		*label;
  struct s_labellist	*next;
}			t_labellist;

typedef struct		s_instlist
{
  t_instruct		*instruct;
  struct s_instlist	*next;
}			t_instlist;

typedef struct	s_op
{
  char		*mnemonique;
  char		nbr_args;
  char		type[MAX_ARGS_NUMBER];
  char		code;
}		t_op;

typedef struct	s_header
{
  char		prog_name[PROG_NAME_LENGTH];
  char		comment[COMMENT_LENGTH];
  char		prog_len_str[PROG_LEN_LENGTH];
}		t_header;

typedef struct	s_cor
{
  t_header	*header;
  char		**file;
  t_labellist	*labels;
  t_instlist	*instructs;
  int		prog_len;
}		t_cor;

#endif /* !MY_ASM_H_ */
