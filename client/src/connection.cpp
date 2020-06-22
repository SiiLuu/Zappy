/*
** EPITECH PROJECT, 2020
** connection
** File description:
** zappy
*/

#include <unistd.h>
#include <iostream>
#include <string>
#include <netinet/in.h>
#include "client.hpp"

extern "C" int connectClient(int port)
{
    struct sockaddr_in serv_addr;
    int sock = 0;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("An error occured with the socket.\n");
        return (84);
    }
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if (connect(sock, (struct sockaddr *)&serv_addr, \
    sizeof(serv_addr)) == -1) {
        printf("An error occured with the connection\n");
        return (84);
    }
    return (sock);
}

extern "C" void connection(int client_socket, int *fd_type, fd_set *fdr, fd_set *fdw)
{
    char *line = NULL;
    size_t size = MAX_BUFFER;
    struct timeval tv = {2, 0};

    FD_ZERO(fdr);
    FD_ZERO(fdw);
    FD_SET(0, fdr);
    FD_SET(client_socket, fdr);
    if (select(client_socket + 1, fdr, fdw, NULL, &tv) == -1) {
        if (errno != EINTR) {
            perror("Select");
            exit(84);
        }
    }
}

extern "C" bool readding(int fd_type, fd_set fdr, int fd_server)
{
    return (FD_ISSET(fd_server, &fdr) ? true : false);
}
