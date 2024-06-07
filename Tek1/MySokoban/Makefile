##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

CC			= 	gcc
CFLAGS		= 	-W -Wall -Werror -Wextra -Iinclude -g3

SRC 		=	$(wildcard src/*.c) \
				$(wildcard src/game/*.c) \
				$(wildcard src/utils/*.c)

OBJ 		= 	$(SRC:.c=.o)

TARGET		= 	my_sokoban

NB_FILES := $(words $(SRC))

.SILENT:	$(OBJ)

all: $(TARGET)

$(TARGET): 	$(OBJ)
	@echo "\033[1;99m\n ❖ Compilation\033[0m\n ╥"
	@echo "\033[5;99m ╠ Files compiled \033[1;94m$(NB_FILES)\033[0m\n ║\033[0m"
	@echo "\033[1;99m ║  \033[1;94msrc/\033[0m\n ╚══╛\033[0m"

	@echo "\033[1;92m\n╔\033[0m"
	@$(CC) -o $(TARGET) $(OBJ) -lncurses
	@echo "\033[1;92m    BUILD   √\n\t\t╝\033[0m"

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(TARGET)

re : fclean all
