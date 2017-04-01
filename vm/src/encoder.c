/*
** encoder.c for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Mar 30 14:06:31 2017 romain pillot
** Last update Wed Apr  5 08:53:20 2017 romain pillot
*/

#include "vm.h"
#include <stdbool.h>

int	bytes_to_int(unsigned char a,
		     unsigned char b,
		     unsigned char c,
		     unsigned char d)
{
  return ((a << 24) + (b << 16) + (c << 8) + d);
}

/*
** char a = 0x78 (01 11 10 00)
** param_type(a, 2)
** -> 3 - 2 = 1
** -> 2 * 1 = 2
** -> a >> 2 = 00 01 11 10
** -> & 3 = 00 00 00 10
*/
char	param_type(char coding_byte, int index)
{
  return ((coding_byte >> (2 * (3 - index))) & 3);
}

bool	valid_program(unsigned char *bytes)
{
  return (bytes_to_int(bytes[0], bytes[1], bytes[2], bytes[3])
	  == COREWAR_EXEC_MAGIC);
}

void	decode_header_name(char name[PROG_NAME_LENGTH], unsigned char *content)
{
  int	i;

  i = -1;
  while (++i < PROG_NAME_LENGTH && content[i + MAGIC_LENGTH])
    name[i] = content[i + MAGIC_LENGTH];
  name[i] = 0;
}
