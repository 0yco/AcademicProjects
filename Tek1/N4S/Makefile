##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC 		=	$(wildcard src/*.c) \
				$(wildcard src/utils/*.c)

OSRC 		=	$(wildcard lib/my/*.c)

OBJ 		= 	$(SRC:.c=.o)

CPPFLAGS	=	-Iinclude

CFLAGS		= 	-W -Wall -Wextra -Iinclude -g3 #-Werror

TARGET		= 	ai
UNIT_TEST = unit_tests

NB_FILES	:=	$(words $(SRC) $(OSRC))

.SILENT:	$(OBJ)

all:	$(TARGET)

$(TARGET): 	$(OBJ)
	@echo "\033[1;99m\n ❖ Compilation\033[0m\n ╥"
	@echo "\033[5;99m ╠ Files compiled \033[1;94m$(NB_FILES)\033[0m\n ║\033[0m"
	@echo "\033[1;99m ║  \033[1;94msrc/\033[0m\n ╠══╛\033[0m"
	@echo "\033[1;99m ║  \033[1;94mlib/my/\033[0m\n ╚══╛\033[0m"

	@echo "\033[1;92m\n╔\033[0m"
	@make -C lib/my/ -s
	@$(CC) -o $(TARGET) $(OBJ) -Llib/my/ -lmy
	@echo "\033[1;92m    BUILD   √\n\t\t╝\033[0m"

clean :
	@make clean -C lib/my/ -s
	@rm -rf $(OBJ)

fclean : clean
	@make fclean -C lib/my/ -s
	@rm -rf $(TARGET)

re :	fclean all
