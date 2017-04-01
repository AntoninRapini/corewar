/*
** my_line_iscode.c for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri Mar 31 19:10:02 2017 Antonin Rapini
** Last update Fri Mar 31 19:11:02 2017 Antonin Rapini
*/

int	my_line_iscode(char *line)
{
  int	i;

  i = 0;
  while (line[i])
    {
      if (line[i] != ' ' && line[i] != '\t')
	{
	  if (line[i] == '#')
	    return (0);
	  return (1);
	}
      i++;
    }
  return (0);
}
