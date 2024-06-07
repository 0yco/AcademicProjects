##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

CC			= 	gcc
CFLAGS		= 	-W -Wall -Werror -Wextra
CPPFLAGS	=	-Iinclude/
LDFLAGS		=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

SRC 		=	$(wildcard src/*.c) \
				$(wildcard src/game/*.c) \
				$(wildcard src/animation/*.c) \
				$(wildcard src/utils/*.c)

OBJ 		= 	$(SRC:.c=.o)

TARGET		= 	my_runner

.SILENT: $(OBJ)

all: $(TARGET)

$(TARGET): 	$(OBJ)
	@echo "\033[1;93mCompilation du src...\033[0m"
	@make -C lib/my/ -s
	@$(CC) -o $(TARGET) $(OBJ) $(LDFLAGS) -Llib/my -lmy
	@echo "\033[1;92mBuild OK!\033[0m"

clean :
	@make clean -C lib/my/ -s
	@rm -rf $(OBJ)

fclean : clean
	@make fclean -C lib/my/ -s
	@rm -rf $(TARGET)

re : fclean all
