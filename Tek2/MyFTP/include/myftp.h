/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myftp-enzo.daumalle
** File description:
** myftp.h
*/

#pragma once

#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdbool.h>


/* MODES */
#define NONE               0
#define ACTIVE             1
#define PASSIVE            2


/* UTILS */
#define NB_CMDS            14
#define UNUSED             __attribute__((unused))
#define PARAMS_CMDS        client_t *client, server_t *server
#define PARAMS_CMDS_UNUSED UNUSED client_t *client, UNUSED server_t *server



/* SERVER */
/// @brief Server structure
typedef struct server_s {
    int fd;
    struct sockaddr_in address;
    char *path;
    char *buffer;
} server_t;



/* CLIENT */
/// @brief Client structure
typedef struct client_s {
    char *username;
    char *password;
    struct sockaddr_in address;
    socklen_t address_len;
    int sd;
    int mode;
} client_t;



/* COMMANDS */
typedef struct builtin_s {
    char *cmd;
    void (*fptr) (PARAMS_CMDS);
} builtin_t;
/// @brief Get the builtin object of the command
/// @param buffer Line of the client
/// @return The builtin object to execute the function
builtin_t *get_builtin(char *buffer);
/// @brief USER command: First step of the login
void user(PARAMS_CMDS);
/// @brief PASS command: Second step of the login
void pass(PARAMS_CMDS);
void quit(PARAMS_CMDS);
void cwd(PARAMS_CMDS);
void cdup(PARAMS_CMDS);
void dele(PARAMS_CMDS);
void pwd(PARAMS_CMDS);
void pasv(PARAMS_CMDS);
void port(PARAMS_CMDS);
/// @brief HELP command: Print the help message
void help(PARAMS_CMDS);
/// @brief NOOP command: Print a success message for ensuring the connection
void noop(PARAMS_CMDS);
void retr(PARAMS_CMDS);
void stor(PARAMS_CMDS);
void list(PARAMS_CMDS);

/* SERVER / CLIENTS */
/// @brief Create the server and listen for client
void server(int port, char *path);
/// @brief Process the server
/// @param server Server structure
void process_server(server_t *server);

/* CHECKER */
bool buffer_is_invalid(char *buffer);
bool is_no_params(char *buffer, int sd);
bool is_data_connection(client_t *client);
bool is_authentified(client_t *client, char *cmd);
