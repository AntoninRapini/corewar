##
## Makefile for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar
## 
## Made by Antonin Rapini
## Login   <antonin.rapini@epitech.net>
## 
## Started on  Fri Mar 31 15:03:27 2017 Antonin Rapini
## Last update Fri Mar 31 15:11:31 2017 Antonin Rapini
##

all 	:
		make -C asm/
		make -C corewar/
clean	:
		make clean -C asm/
		make clean -C corewar/

fclean	:
		make fclean -C asm/
		make fclean -C corewar/

re 	:	fclean all
