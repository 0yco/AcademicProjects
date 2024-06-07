##
## EPITECH PROJECT, 2021
## my_printf
## File description:
## Makefile
##

LIB_SRC		= 	$(wildcard src/*.c)

LIB_OBJ 	= 	$(LIB_SRC:.c=.o)

TARGET_LIB	= 	libmy.a

all: $(TARGET_LIB)

$(TARGET_LIB):	$(LIB_OBJ)
	@ar src $(TARGET_LIB) $(LIB_OBJ)

clean:
	@rm -rf $(LIB_OBJ)

fclean: clean
	@rm -rf $(TARGET_LIB)

re : fclean all
