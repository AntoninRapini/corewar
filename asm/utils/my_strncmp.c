/*
** my_strcnmp.c for my_strncmp in /home/antonin.rapini/CPool_Day06/tests
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon Oct 10 10:19:01 2016 Antonin Rapini
** Last update Fri Mar 10 17:36:24 2017 Antonin Rapini
*/

#include <stdio.h>

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (s1[i] && s2[i] && i < n)
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i++;
    }
  return (0);
}
