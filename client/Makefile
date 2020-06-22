##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## myteams
##

SRCFOLDER = ./src/
SRCCOMMANDS = ./src/commands/
SRCGRAPHIC = ./../graphical/
SRCIA = ./src/ia/

SRC		=	$(SRCFOLDER)loop_functions.cpp				\
			$(SRCFOLDER)client.cpp						\
			$(SRCFOLDER)help.cpp						\
			$(SRCFOLDER)command_IA.cpp					\
			$(SRCFOLDER)connection.cpp					\
			$(SRCFOLDER)myStrToWordVector.cpp			\
			$(SRCCOMMANDS)commandHandler.cpp			\
			$(SRCCOMMANDS)broadcast.cpp					\
			$(SRCCOMMANDS)collectRessource.cpp			\
			$(SRCCOMMANDS)commandParameter.cpp			\
			$(SRCCOMMANDS)dropRessource.cpp				\
			$(SRCCOMMANDS)eggHatching.cpp				\
			$(SRCCOMMANDS)eggLaid.cpp					\
			$(SRCCOMMANDS)endIncantation.cpp			\
			$(SRCCOMMANDS)expulsion.cpp					\
			$(SRCCOMMANDS)gameEnded.cpp					\
			$(SRCCOMMANDS)hatchedEggDeath.cpp			\
			$(SRCCOMMANDS)layEgg.cpp					\
			$(SRCCOMMANDS)mapSize.cpp					\
			$(SRCCOMMANDS)playerConnection.cpp			\
			$(SRCCOMMANDS)playerConnectionEgg.cpp		\
			$(SRCCOMMANDS)playerDeath.cpp				\
			$(SRCCOMMANDS)playerInventory.cpp			\
			$(SRCCOMMANDS)playerLevel.cpp				\
			$(SRCCOMMANDS)playerPosition.cpp			\
			$(SRCCOMMANDS)serverMessage.cpp				\
			$(SRCCOMMANDS)startIncantation.cpp			\
			$(SRCCOMMANDS)teamsName.cpp					\
			$(SRCCOMMANDS)tileOrMapContent.cpp			\
			$(SRCCOMMANDS)timeUnitModif.cpp				\
			$(SRCCOMMANDS)timeUnitRequest.cpp			\
			$(SRCCOMMANDS)unknownCommand.cpp			\
			$(SRCGRAPHIC)egg.cpp						\
			$(SRCGRAPHIC)inca.cpp						\
			$(SRCGRAPHIC)players.cpp					\
			$(SRCGRAPHIC)rsrc.cpp						\
			$(SRCGRAPHIC)hud.cpp						\
			$(SRCGRAPHIC)sfml.cpp						\
			$(SRCIA)elevation.cpp 						\
			$(SRCIA)level_priority.cpp 					\
			$(SRCIA)inventory.cpp						\
			$(SRCIA)path_finding.cpp 					\
			$(SRCIA)trantorian.cpp						\

TESTSRC	=	$(SRCIA)test_inventory.cpp	\
			$(SRCIA)test_priority.cpp	\


SRCMAIN =	$(SRCFOLDER)main.cpp

CXX = g++
CXXFLAGS = -W -Wextra -I./include/ -I./../graphical/
CFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

BINARYNAME = ../zappy_ai

OBJ = $(SRC:.cpp=.o)

OBJMAIN = $(SRCMAIN:.cpp=.o)

all: $(BINARYNAME)

$(BINARYNAME): $(OBJ) $(OBJMAIN)
	$(CXX) -o $(BINARYNAME) $(OBJMAIN) $(OBJ) $(CFLAGS) $(CXXFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJMAIN)
	$(RM) *.o

fclean: clean
	$(RM) $(BINARYNAME)

re: fclean all

debug:	CXXFLAGS += -g3
debug:	fclean all

mac:	CXXFLAGS += -stdlib=libc++ -std=c++11
mac:	fclean all

.PHONY: all clean fclean re
