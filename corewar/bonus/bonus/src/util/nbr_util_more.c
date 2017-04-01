/*
** nbr_util_more.c for  in /home/romain.pillot/projects/CPE_2016_corewar/vm
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sat Apr  1 08:46:33 2017 romain pillot
** Last update Sun Apr  2 14:18:46 2017 Antonin Rapini
*/

#include "util.h"

static void	putch(char c, int *counter, int bline)
{
  if (*counter && !(*counter % bline))
    display_char(c, false);
}

static void	trash_split(int bline, int nbr, int base_length, int *counter)
{
  int		div;
  char		*base;

  div = 1;
  base = "0123456789abcdef";
  while (nbr / div >= base_length)
    {
      div = div * base_length;
    }
  while (div > 1)
    {
      (*counter)++;
      display_char(base[nbr / div], false);
      putch('\n', counter, bline);
      nbr = nbr % div;
      div = div / base_length;
    }
  (*counter)++;
  display_char(base[nbr / div], false);
}

void     putnbr_hexa(unsigned char nbr, int *counter, int bline)
{
  int   base_length;
  char *base;

  base = "0123456789abcdef";
  base_length = 0;
  if (nbr < 0)
    {
      (*counter)++;
      display_char(45, false);
      putch('\n', counter, bline);
      nbr = -nbr;
    }
  base_length = str_length(base);
  trash_split(bline, nbr, base_length, counter);
}
