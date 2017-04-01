/*
** get_next_line.c for getnextline in /home/antonin.rapini/ModulesTek1/GetNextLine/CPE_2016_getnextline
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon Jan  2 18:01:21 2017 Antonin Rapini
** Last update Tue Mar 28 07:33:33 2017 Antonin Rapini
*/

#include <stdlib.h>
#include <unistd.h>
#include "utils.h"

void	my_clear_buffer(char *buffer)
{
  int	i;

  i = 0;
  while (i < READ_SIZE)
    {
      buffer[i] = '\0';
      i++;
    }
}
void	my_changebuffer(char *buffer, int size)
{
  char	tmpbuffer[READ_SIZE];
  int	i;

  i = 0;
  while (buffer[i + size + 1])
    {
      tmpbuffer[i] = buffer[i + size + 1];
      i++;
    }
  tmpbuffer[i] = '\0';
  i = 0;
  while (tmpbuffer[i])
    {
      buffer[i] = tmpbuffer[i];
      i++;
    }
  while (i < READ_SIZE)
    {
      buffer[i] = '\0';
      i++;
    }
}

char	*my_realloc(char *str, char *buffer, int size)
{
  char	*newstr;
  int	strsize;
  int	i;

  strsize = size;
  i = 0;
  if (str)
    while (str[i++])
      strsize++;
  if ((newstr = malloc(sizeof(char) * (strsize + 1))) == NULL)
    return (NULL);
  i = 0;
  while (i++ < strsize)
    if (i - 1 < strsize - size)
      newstr[i - 1] = str[i - 1];
    else
      newstr[i - 1] = buffer[i - 1 - strsize + size];
  newstr[i - 1] = '\0';
  free(str);
  return (newstr);
}

int	my_fillstr(char *buffer, char **str)
{
  int	i;
  char	last;

  i = 0;
  while (buffer[i] && buffer[i] != '\n')
    i++;
  *str = my_realloc(*str, buffer, i);
  last = buffer[i];
  my_changebuffer(buffer, i);
  return (*str == NULL || last == '\n' ? 1 : 0);
}

char		*get_next_line(const int fd)
{
  static char	buffer[READ_SIZE + 1] = "";
  static int	prevfd = -1;
  int		size;
  char		*str;

  if (fd != prevfd)
    my_clear_buffer(buffer);
  prevfd = fd;
  size = 1;
  str = NULL;
  while (READ_SIZE > 0 && size > 0)
    {
      if (buffer[0] == '\0')
	{
	  size = read(fd, buffer, READ_SIZE);
	  buffer[size] = '\0';
	}
      if (size > 0 && my_fillstr(buffer, &str))
	return (str);
    }
  return (str != NULL ? str : NULL);
}
