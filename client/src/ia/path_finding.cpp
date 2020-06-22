/*
** EPITECH PROJECT, 2020
** path_finding.cpp
** File description:
** path_finding.cpp
*/

#include "path_finding.hpp"

Path::Path() {};

Path::~Path() {};

int Path::find_level(int index, int i)
{
    int lines = 0;
    int nbr_rock_line = 3;
    int rock = 3;

    while (lines < 9) {
        if (index <= rock) {
            lines++;
            break;
        }
        nbr_rock_line += 2;
        rock += nbr_rock_line;
        lines++;
    }
    return (i == 1 ? lines : ((rock + (rock - nbr_rock_line + 1)) / 2));
}

std::vector<int> Path::find_lines(int search, std::vector<int> path)
{
    int lines = find_level(search, 1);
    int middle_line = find_level(search, 2);

    for (int i = 0; i < lines; i++)
        path.push_back(Forward);
    if (middle_line > search) {
        path.push_back(Left);
        middle_line -= search;
        for (int i = 0; i < middle_line; i++)
            path.push_back(Forward);
    }
    else if (middle_line < search){
        path.push_back(Right);
        search -= middle_line;
        for (int i = 0; i < search; i++)
            path.push_back(Forward);
    }
    return (path);
}

std::vector<int> Path::find_path(std::vector<std::string> search, std::string object)
{
    size_t i = 0;
    std::vector<int> path;

    for (; i < search.size(); i++) {
        if (search[i].find(object) != std::string::npos && i == 0) {
            path.push_back(Take);
            break;
        }
        else if (search[i].find(object) != std::string::npos) {
            path = find_lines(i, path);
            path.push_back(Take);
            break;
        }
    }
    return (path);
}
