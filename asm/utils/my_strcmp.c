/*
** my_strcmp.c for my_strcmp in /home/antonin.rapini/CPool_Day06/tests
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon Oct 10 10:19:01 2016 Antonin Rapini
** Last update Wed Mar  1 17:51:58 2017 Antonin Rapini
*/

int	my_strcmp(char *s1, char *s2)
{
  int	index;

  index = 0;
  while (s1[index] != '\0' && s2[index] != '\0')
    {
      if (s1[index] != s2[index])
	return (-1);
      index++;
    }
  return (s1[index] != s2[index]);
}
