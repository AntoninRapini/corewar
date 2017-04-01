/*
** util.h for  in /home/romain.pillot/projects/PSU_2016_minishell1/include
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Mar  2 16:17:22 2017 romain pillot
** Last update Tue Apr  4 21:31:20 2017 romain pillot
*/

#ifndef UTIL_H_
# define UTIL_H_

#include <stdbool.h>

char	*scan_line(const int file);

void    display(char *str, bool err);

void    display_char(char c, bool err);

int	count_char(char *str, char c);

char	*rev_substr(char *str, char c, int index);

char	*trimstr(char *str, char c);

bool	equalstr(char *a, char *b);

char	**splitstr(char *str, char delimiter);

int	str_length(char *str);

bool	start_withstr(char *str, char *charset);

bool	end_withstr(char *str, char *charset);

char	*tab_start_withstr(char **tab, char *charset);

int	tab_length(char **tab);

bool	tab_containstr(char **tab, char *str);

char	*strdupl(char *str);

char	*strdup_len(char *str, int len);

void	safe_freetab(char **tab);

char	*concatstr(char *a, char *b, bool free_a);

bool	safe_freesub(char **ptr, bool free_sub);

bool	safe_free(void *ptr);

int	getnbr(char *str);

void	putnbr(int nbr, bool err);

void	putnbr_hexa(unsigned char nbr, int *counter, int bline);

void	display_format(char *str, ...);

void    fdisplay_format(char *str, ...);

bool	containstr(char *str, char *charset);

char	**filltab(char **tab, void *e, int size);

char	*fillstr(char *ptr, char c, int size);

char	*copystr(unsigned char *from, int flen,
		 unsigned char *to, int index);

void	*memfill(void *ptr, int val, int bytes);

char	*get_filename(char *str);

#endif /* !UTIL_H_ */
