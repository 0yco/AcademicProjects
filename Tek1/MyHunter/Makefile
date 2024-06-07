##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

CC			= 	gcc
CFLAGS		= 	-W -Wall -Werror -Wextra
LDFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

SRC 		=	$(wildcard src/*.c)

OBJ 		= 	$(SRC:.c=.o)

TARGET		= 	my_hunter

all: $(TARGET)

$(TARGET): 	$(OBJ)
	@$(CC) -o $(TARGET) $(OBJ) -Iinclude/ $(LDFLAGS)
	@echo "\nBuild OK!"

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(TARGET)

re : fclean all
