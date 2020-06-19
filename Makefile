 
##
## PERSONNAL PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC		=	src/Main.cpp								\
			src/Game.cpp								\
			src/Entity.cpp								\
			src/States/GameState.cpp					\
			src/States/MainMenuState.cpp				\
			src/States/State.cpp						\
			src/Resources/Button.cpp

OBJ	=	$(SRC:.cpp=.o)

EXEC	=	"The Elder Scrolls 5 - Skyrim - 2D Edition.exe"

MV		=	mv

CC		=	gcc

RM		=	rm -f

CXXFLAGS	+=	-Wextra -Wall -I./include

CXXFLAGS	+=	-g

SFML	=	-lstdc++ -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-window

all: $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(CFLAGS) $(SFML)

clean:
	$(RM) $(OBJ)

debug:
	$(CC) $(EXEC) $(CFLAGS) $(SRC)

fclean:
	$(RM) $(OBJ)
	$(RM) $(EXEC)

re: fclean all

.PHONY: all clean fclean re
