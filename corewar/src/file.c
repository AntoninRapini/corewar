/*
** file.c for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Mar 30 14:03:00 2017 romain pillot
** Last update Sun Apr  2 14:20:21 2017 Antonin Rapini
*/

#include "util.h"
#include "file.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char			*file_content(t_process *process, int file)
{
  unsigned char		*content;
  unsigned char		buffer[1024 + 1];
  int			bytes;
  int			len;

  content = NULL;
  len = 0;
  while ((bytes = read(file, buffer, 1024)) && bytes != -1)
    {
      buffer[bytes] = 0;
      len += bytes;
      content = !content ?
	copystr(buffer, bytes, malloc(sizeof(char) * (len + 1)), 0) :
	copystr(buffer, bytes, realloc(content,
				       sizeof(char) * (len + 1)), len - bytes);
    }
  if (bytes == -1)
    {
      display("Error: can't read the file\n", true);
      safe_free(content);
      return (NULL);
    }
  process->data_len = len - HEADER_LENGTH;
  return (content);
}

int		open_file(char *file_name)
{
  int		file;

  if ((file = open(file_name, O_RDONLY)) == -1)
    fdisplay_format("%s: can't open the file\n", file_name);
  return (file);
}
