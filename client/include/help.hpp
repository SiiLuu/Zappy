/*
** EPITECH PROJECT, 2020
** help.hpp
** File description:
** help.hpp
*/

#ifndef HELP_H_
#define HELP_H_

#include <vector>
#include <string>
#include <iostream>

class help
{
    private:
    public:
        help();
        ~help();
        bool isWrongParameters(int argc, std::vector<std::string> av);
        bool checkParameters(std::vector<std::string> av);
        std::string machine;
        std::string teamName;
        int port;
};




#endif /* !HELP_H_ */