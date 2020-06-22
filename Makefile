##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Zappy
##

all:
	make --no-print-directory -C ./server
	make --no-print-directory -C ./client

clean:
	make clean --no-print-directory -C ./server
	make clean --no-print-directory -C ./client

fclean: clean
	make fclean --no-print-directory -C ./server
	make fclean --no-print-directory -C ./client

re: fclean all

debug:	make debug --no-print-directory -C ./server
debug:	make debug --no-print-directory -C ./client
debug:	fclean all

mac:
	make --no-print-directory -C ./server
	make mac --no-print-directory -C ./client

.PHONY: all clean fclean re debug mac
