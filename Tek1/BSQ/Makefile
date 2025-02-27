##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

CC			= 	gcc
CFLAGS		= 	-W -Wall -Werror -Wextra -Iinclude

SRC 		=	$(wildcard src/*.c)

OBJ 		= 	$(SRC:.c=.o)

TARGET		= 	bsq

all: $(TARGET)

$(TARGET): 	$(OBJ)
	@make -C lib/my/ -s
	@$(CC) -o $(TARGET) $(OBJ) -Llib/my/ -lmy
	@echo "\nBuild OK!"

clean :
	@make clean -C lib/my/ -s
	@rm -rf $(OBJ)

fclean : clean
	@make fclean -C lib/my/ -s
	@rm -rf $(TARGET)

re : fclean all
