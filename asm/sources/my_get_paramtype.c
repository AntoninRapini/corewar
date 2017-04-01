/*
** my_get_paramtype.c for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Mar 29 18:04:49 2017 Antonin Rapini
** Last update Sat Apr  1 07:39:09 2017 Antonin Rapini
*/

#include "utils.h"
#include "my_asm.h"

int	my_is_direct(t_param *param)
{
  int	ret;

  if (param->param[0] == '%')
    {
      if (param->param[1] == ':')
	{
	  param->islabel = 1;
	  return (2);
	}
      my_getnbr(param->param + 1, &ret);
      if (ret == 0)
	return (2);
    }
  return (0);
}

int	my_is_indirect(t_param *param)
{
  int	ret;

  if (param->param[0] == ':')
    {
      param->islabel = 1;
      return (4);
    }
  my_getnbr(param->param, &ret);
  if (ret == 0)
    return (4);
  return (0);
}

int	my_is_register(t_param *param)
{
  int	ret;
  int	number;

  if (param->param[0] == 'r')
    {
      number = my_getnbr(param->param + 1, &ret);
      if (ret != 0 || number <= 0 || number > 16)
	return (-1);
      return (1);
    }
  return (0);
}

char	my_get_paramtype(t_param *param)
{
  int	ret;

  param->islabel = 0;
  if ((ret = my_is_indirect(param)) != 0)
    return ((char)ret);
  if ((ret = my_is_direct(param)) != 0)
    return ((char)ret);
  if ((ret = my_is_register(param)) != 0)
    return ((char)ret);
  return (-1);
}
