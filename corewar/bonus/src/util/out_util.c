/*
** display.c for  in /home/romain.pillot/projects/PSU_2016_navy/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Tue Feb  7 14:39:21 2017 romain pillot
** Last update Mon Mar 13 04:42:50 2017 romain pillot
*/

#include "util.h"
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int	str_length(char *str)
{
  int		i;

  i = 0;
  while (str && str[i] && ++i);
  return (i);
}

void	display(char *str, bool err)
{
  if (str)
    write(err ? 2 : 1, str, str_length(str));
}

void	display_char(char c, bool err)
{
  write(err ? 2 : 1, &c, 1);
}

void		display_format(char *str,  ...)
{
  va_list	args;

  va_start(args, str);
  while (*str)
    {
      if (*str == '%')
	{
	  str++;
	  if (*str == 'c')
	    display_char(va_arg(args, int), false);
	  else if (*str == 's')
	    display(va_arg(args, char *), false);
	  else if (*str == 'd')
	    putnbr(va_arg(args, int), false);
	}
      else
	display_char(*str, false);
      str++;
    }
  va_end(args);
}

void		fdisplay_format(char *str,  ...)
{
  va_list       args;

  va_start(args, str);
  while (*str)
    {
      if (*str == '%')
	{
	  str++;
	  if (*str == 'c')
	    display_char(va_arg(args, int), true);
	  else if (*str == 's')
	    display(va_arg(args, char *), true);
	  else if (*str == 'd')
	    putnbr(va_arg(args, int), true);
	}
      else
	display_char(*str, true);
      str++;
    }
  va_end(args);
}
