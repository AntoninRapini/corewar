/*
** disp_stdarg.c for disp_stdarg in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_printf_bootstrap
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Nov  8 15:51:15 2016 Antonin Rapini
** Last update Sat Mar 11 18:47:20 2017 Antonin Rapini
*/

#include "my_miniprintf.h"

void my_print(va_list *list, int id)
{
  if (id == 0)
    my_put_nbr(va_arg(*list, int));
  else if (id == 1)
    my_putchar(va_arg(*list, int));
  else if (id == 2)
    my_putstr(va_arg(*list, char *));
}

t_format	*my_create_format_arr()
{
  t_format	*arr;

  if ((arr = malloc(sizeof(t_format) * 4)) == NULL)
    return (NULL);
  arr[0].key = 'i';
  arr[0].id = 0;
  arr[1].key = 'c';
  arr[1].id = 1;
  arr[2].key = 's';
  arr[2].id = 2;
  arr[3].key = '\0';
  arr[3].id = -1;
  return (arr);
}

int my_call_printfnc(va_list *list, char *s, t_format *arr)
{
  while ((*arr).key)
    {
      if ((*arr).key == *(s + 1))
	{
	  my_print(list, (*arr).id);
	  return (2);
	}
      arr++;
    }
  my_putchar(*s);
  return (1);
}

int		my_miniprintf(char *s, ...)
{
  va_list	list;
  t_format	*arr;

  if ((arr = my_create_format_arr()) == NULL)
    return (1);
  va_start(list, s);
  while (*s)
    {
      if (*s == '%' && *(s + 1))
	s += my_call_printfnc(&list, s, arr);
      else
	{
	  my_putchar(*s);
	  s++;
	}
    }
  va_end(list);
  return (0);
}
