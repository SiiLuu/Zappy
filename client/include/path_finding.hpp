/*
** EPITECH PROJECT, 2020
** path_finding.hpp
** File description:
** path_finding.hpp
*/

#ifndef PATH_FINDING_HPP_
#define PATH_FINDING_HPP_

#include <vector>
#include <string>
#include <algorithm>

class Path {
    public:
        Path();
        ~Path();
        std::vector<int> find_path(std::vector<std::string>, std::string);

        enum direction {
            None,
            Forward,
            Backward,
            Right,
            Left,
            Take
        };

    private:
        int find_level(int, int);
        std::vector<int> find_lines(int, std::vector<int>);
        int find_level(int);
};

#endif /* !PATH_FINDING_HPP_ */
