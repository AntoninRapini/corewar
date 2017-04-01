/*
** my_get_header.c for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Mar 28 06:44:39 2017 Antonin Rapini
** Last update Sun Apr  2 09:02:32 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "utils.h"
#include "my_asm.h"

int	get_offset(char *str)
{
  int	i;

  i = 0;
  while (str[i] && (str[i] == ' ' || str[i] == '\t'))
      i++;
  return (i);
}

int     fill_header(char *buffer, char *prog_name, char *id, int maxsize)
{
  int	i;
  int	j;

  j = 0;
  i = get_offset(buffer);
  if (my_strncmp(buffer + i, id, my_strlen(id)) != 0)
    return (1);
  i += my_strlen(id);
  i += get_offset(buffer + i);
  if (buffer[i++] != '"')
    return (2);
  while (buffer[i] && buffer[i] != '"')
    {
      if (j >= maxsize)
	return (2);
      prog_name[j] = buffer[i];
      j++;
      i++;
    }
  if (!buffer[i])
    return (2);
  i++;
  if (my_line_iscode(buffer + i))
    return (1);
  return (0);
}

int	my_get_header(char **file, t_header *header)
{
  int	status;
  int	ret;
  int	i;

  i = 0;
  status = 0;
  while (status != 2 && file[i])
    {
      if (my_line_iscode(file[i]))
	{
	  ret = status == 0 ?
	    fill_header(file[i], header->prog_name, ".name", PROG_NAME_LENGTH) :
	    fill_header(file[i], header->comment, ".comment", COMMENT_LENGTH);
	  if ((ret != 0 && status == 0) || (ret == 2 && status == 1))
	    return (-1);
	  if (ret == 1 && status == 1)
	    return (i);
	  status++;
	}
      i++;
    }
  return (status < 1 ? -1 : i);
}
