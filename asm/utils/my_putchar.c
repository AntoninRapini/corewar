/*
** my_putchar.c for my_putchar in /home/antonin.rapini/tocompile
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Oct 12 09:17:28 2016 Antonin Rapini
** Last update Mon Oct 17 11:58:54 2016 Antonin Rapini
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
