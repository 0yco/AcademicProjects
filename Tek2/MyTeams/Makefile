##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

CC    =    gcc
CFLAGS    =    -Iinclude
LDFLAGS    =    -Llibs/myteams -lmyteams -luuid

SRC_SERVER    =		$(wildcard src/server/*.c) \
                	$(wildcard src/utils/*.c) \
                	$(wildcard src/server/database/*.c) \
                	$(wildcard src/server/features/*.c) \
                	$(wildcard src/server/features/channel/*.c) \
                	$(wildcard src/server/features/reply/*.c) \
                	$(wildcard src/server/features/subscribe/*.c) \
                	$(wildcard src/server/features/team/*.c) \
					$(wildcard src/server/features/thread/*.c) \
					$(wildcard src/server/features/user/*.c)
BIN_SERVER    =    myteams_server
OBJ_SERVER    =    $(SRC_SERVER:.c=.o)

SRC_CLIENT    =		$(wildcard src/client/*.c) \
                	$(wildcard src/client/features_cmds/*.c) \
					$(wildcard src/utils/*.c)

BIN_CLIENT    =    myteams_cli
OBJ_CLIENT    =    $(SRC_CLIENT:.c=.o)

all:    server client

server:    $(OBJ_SERVER)
	$(CC) -o $(BIN_SERVER) $(OBJ_SERVER) $(LDFLAGS)

client:    $(OBJ_CLIENT)
	$(CC) -o $(BIN_CLIENT) $(OBJ_CLIENT) $(LDFLAGS)

clean:
	rm -f $(OBJ_SERVER)
	rm -f $(OBJ_CLIENT)

fclean:    clean
	rm -f $(BIN_SERVER)
	rm -f $(BIN_CLIENT)

re:    fclean all

.PHONY:    all server client clean fclean re