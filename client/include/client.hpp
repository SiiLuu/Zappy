/*
** EPITECH PROJECT, 2020
** client
** File description:
** zappy
*/

#ifndef CLIENT_H_
#define CLIENT_H_

#define MAX_BUFFER 4096
#define CORRECT 0
#define ERROR 84
#define SOCKET_ERROR -1

enum {
    READ,
    WRITE
};

#include "sfml.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <stdbool.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <csignal>
#include <string>
#include <netinet/in.h>
#include "help.hpp"

class client
{
    public:
        client();
        ~client();
        void initFdSet(int, int, fd_set *, fd_set *);
        void checkRead(fd_set, int, int);
        char *getCommand(int *);
        virtual int clientLoop(int) = 0;
        virtual void iaLoop(int) = 0;
        void graphicalLoop(int);
        void checkWrite(fd_set, int *, int, const char *);
        virtual void which_command(std::string);
        std::string machine;
        std::string command_not_finished;
        std::string teamName;
        std::unique_ptr<Sfml> _sfml;
        std::vector<std::string> queue;
        int nb_player_connected;
        int port;
        int sock;
        fd_set fdr;
        fd_set fdw;

        //IA Command
        std::vector<std::string> cmd_Inventory(void);
        std::string cmd_Forward(void);
        std::string cmd_Right(void);
        std::string cmd_Left(void);
        std::vector<std::string> cmd_Look(void);
        std::string cmd_Broadcast(std::string);
        std::string cmd_Connect(void);
        std::string cmd_Fork(void);
        std::string cmd_Eject(void);
        std::string cmd_Take_obj(std::string);
        std::string cmd_Set_obj(std::string);
        std::string cmd_Incantation(void);
        std::string server_answer(int, const char *);

    private:
        int find_coord(int);
        void initialize_graphical(int);

};

extern "C" {
    int connectClient(int);
    void connection(int, int *, fd_set *, fd_set *);
    bool readding(int, fd_set, int);
}

#endif /* !CLIENT_H_ */
