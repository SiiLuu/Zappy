/*
** EPITECH PROJECT, 2020
** loop_functions.c
** File description:
** myteams
*/

#include "client.hpp"

void client::checkRead(fd_set fdr, int fd_type, int fd_server)
{
    char buffer[MAX_BUFFER];
    std::string delimiter = "\n";
    size_t pos = 0;
    std::string token;

    if (readding(fd_type, fdr, fd_server) == true) {
        bzero(buffer, sizeof(buffer));
        if (read(fd_server, buffer, sizeof(buffer)) == -1)
            perror("READ");
        std::string command(buffer);
        while ((pos = command.find(delimiter)) != std::string::npos) {
            token = command.substr(0, pos);
            token = this->command_not_finished.append(token);
            this->command_not_finished.clear();
            this->queue.push_back(token);
            command.erase(0, pos + delimiter.length());
        }
        if (!command.empty())
            this->command_not_finished = command;
    }
}

void client::initFdSet(int fd_cli, int fd_type, fd_set *fdr, fd_set *fdw)
{
    FD_ZERO(fdr);
    FD_ZERO(fdw);
    FD_SET(0, fdr);
    if (fd_type == READ)
        FD_SET(fd_cli, fdr);
    else
        FD_SET(fd_cli, fdw);
}