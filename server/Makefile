##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## myteams
##

SRCFOLDER = ./src/

UTILSFOLDER = ./src/utils/

CLIENTFOLDER = ./src/client_management/

COMMANDFOLDER =	./src/commands/

SRC		=	$(SRCFOLDER)create_server.c				\
			$(SRCFOLDER)server_loop.c				\
			$(SRCFOLDER)server_disconnection.c		\
			$(SRCFOLDER)initiate_server.c			\
			$(SRCFOLDER)new_client.c				\
			$(SRCFOLDER)args_handling.c				\
			$(SRCFOLDER)tools.c						\
			$(CLIENTFOLDER)check_teams.c			\
			$(CLIENTFOLDER)manage_client.c			\
			$(UTILSFOLDER)my_str_to_word_array.c			\
			$(UTILSFOLDER)path_finding.c					\
			$(UTILSFOLDER)check_slots.c						\
			$(COMMANDFOLDER)map_content.c					\
			$(COMMANDFOLDER)map_size.c						\
			$(COMMANDFOLDER)player_inventory.c				\
			$(COMMANDFOLDER)player_level.c					\
			$(COMMANDFOLDER)player_pos.c					\
			$(COMMANDFOLDER)teams_name.c					\
			$(COMMANDFOLDER)tile_content.c					\
			$(COMMANDFOLDER)time_modif.c					\
			$(COMMANDFOLDER)time_request.c					\
			$(COMMANDFOLDER)command_parser.c				\
			$(COMMANDFOLDER)cmd_broadcast.c					\
			$(COMMANDFOLDER)cmd_connect_nbr.c				\
			$(COMMANDFOLDER)cmd_eject.c						\
			$(COMMANDFOLDER)cmd_fork.c						\
			$(COMMANDFOLDER)cmd_forward.c					\
			$(COMMANDFOLDER)cmd_incantation.c				\
			$(COMMANDFOLDER)cmd_inventory.c					\
			$(COMMANDFOLDER)cmd_left.c						\
			$(COMMANDFOLDER)cmd_right.c						\
			$(COMMANDFOLDER)cmd_set.c						\
			$(COMMANDFOLDER)cmd_take.c						\
			$(COMMANDFOLDER)cmd_look.c						\
			$(COMMANDFOLDER)look_tiles.c					\
			$(COMMANDFOLDER)elevation.c						\
			$(COMMANDFOLDER)elevation_second.c				\


SRCMAIN =	$(SRCFOLDER)main.c

CXX = gcc
CFLAGS = -W -Wextra -I./include -lm

BINARYNAME = ../zappy_server

OBJ = $(SRC:.c=.o)

OBJMAIN = $(SRCMAIN:.c=.o)

all: $(BINARYNAME)

$(BINARYNAME): $(OBJ) $(OBJMAIN)
	$(CXX) -o $(BINARYNAME) $(OBJMAIN) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJMAIN)
	$(RM) *.o

fclean: clean
	$(RM) $(BINARYNAME)

re: fclean all

debug:	CFLAGS += -g3
debug:	fclean all

.PHONY: all clean fclean re
