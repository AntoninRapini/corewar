/*
** my_getnbr.c for my_getnbr in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_printf/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun Nov 20 00:36:16 2016 Antonin Rapini
** Last update Fri Mar 31 10:06:11 2017 Antonin Rapini
*/

int my_getnbr_rec(char *str, int nbr, int sign, int *ret)
{
  if (*str == '-')
    return (my_getnbr_rec(str + 1, nbr, sign * -1, ret));
  else if (*str >= '0' && *str <= '9')
    return (my_getnbr_rec(str + 1, (nbr * 10) + (*str - 48), sign, ret));
  else if (*str == '\0')
    return (nbr * sign);
  else
    {
      if (ret)
	(*ret) = -1;
      return (nbr * sign);
    }
}

int my_getnbr(char *str, int *ret)
{
  if (ret)
    (*ret) = 0;
  return (my_getnbr_rec(str, 0, 1, ret));
}
