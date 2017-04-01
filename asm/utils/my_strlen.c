/*
** my_strlen.c for my_strlen in /home/antonin.rapini/CPool_Day04
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Oct  6 14:02:36 2016 Antonin Rapini
** Last update Wed Mar 29 06:40:12 2017 Antonin Rapini
*/

int	my_strlen(char *str)
{
  int	counter;

  counter = 0;
  if (str)
    {
      while (str[counter])
	counter++;
    }
  return (counter);
}
