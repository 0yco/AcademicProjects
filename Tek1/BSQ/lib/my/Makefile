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

all: $(TARGET_LIB)

$(TARGET_LIB):	$(LIB_OBJ)
	@ar src $(TARGET_LIB) $(LIB_OBJ)
	@echo "\nLib OK!"

clean:
	@rm -rf $(LIB_OBJ)

fclean: clean
	@rm -rf $(TARGET_LIB)

re : fclean all
