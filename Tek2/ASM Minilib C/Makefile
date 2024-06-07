##
## EPITECH PROJECT, 2023
## MiniLibC
## File description:
## Makefile
##

AS          =   nasm

ASFLAGS     =   -f elf64

SRC        =   $(wildcard src/*.asm) \
               $(wildcard bonus/*.asm)

OBJ        =   $(SRC:.asm=.o)

TARGET      =   libasm.so

TEST_SRC   =   $(wildcard tests/*.c)

TEST_OBJ   =   $(TEST_SRC:.c=.o)

TEST_TARGET =   test_libasm

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -nostdlib -shared -fPIC $(OBJ) -o $(TARGET)

%.o : %.asm
	$(AS) $(ASFLAGS) -o $@ $<

clean:
	$(RM) $(OBJ) $(TEST_OBJ)

fclean: clean
	$(RM) $(TARGET) $(TEST_TARGET)

re:	fclean all

test: $(TEST_OBJ)
	$(CC) $(TEST_OBJ) -o $(TEST_TARGET) -L. -lasm -lcriterion
