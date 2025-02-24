##
## EPITECH PROJECT, 2021
## Lib My
## File description:
## Makefile
##

CC			=	gcc
CFLAGS		=	-W -I../../include
# -Wall -Wextra -Werror

LIB_SRC		= 	$(wildcard *.c) \
				$(wildcard my_printf/*.c) \


LIB_OBJ 	= 	$(LIB_SRC:.c=.o)

TARGET_LIB	= 	libmy.a

.SILENT:	$(OBJ)

all: $(TARGET_LIB)

$(TARGET_LIB):	$(LIB_OBJ)
	@echo "\033[1;93mCompilation de libmy...\033[0m"
	@ar src $(TARGET_LIB) $(LIB_OBJ)
	@echo "\033[1;92m\nLIB OK!\033[0m"

clean:
	@rm -rf $(LIB_OBJ)

fclean: clean
	@rm -rf $(TARGET_LIB)

re : fclean all
