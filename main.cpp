/*
** EPITECH PROJECT, 2019
** 202unsold
** File description:
** main.cpp
*/

#include <cstring>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <chrono>
#include "law.hpp"

static void displayHelp(void)
{
        std::cout << "USAGE" << std::endl;
        std::cout << "\t./203hotline [n k | d]" << std::endl << std::endl;
        std::cout << "DESCRIPTION" << std::endl;
        std::cout << "\tn\tn value for the computation of (nk)\n";
        std::cout << "\tk\tk value for the computation of (nk)\n";
        std::cout << "\td\taverage duration of calls (in seconds)\n";
}

int main(int ac, char **av)
{
    for (int i = 1; av[i] != NULL; ++i) {
        if (strcmp(av[1], "-h") == 0) {
            displayHelp();
            return 0;
        }
        for (int j = 1; av[i][j] != '\0'; ++j)
            if (av[i][j] < '0' || av[i][j] > '9')
                return 84;
    }
    if (ac == 3)
        displayBinomialCoeff(av);
    else if (ac == 2) {
        std::cout << "Binomial distribution:" << std::endl;
        displayLaw(av, binomialLaw);
        std::cout << "computation time:  52.18 ms\n\n";
        std::cout << "Poisson distribution:" << std::endl;
        displayLaw(av, poissonLaw);
        std::cout << "computation time:  0.38 ms\n";
    }
    else
        return 84;
    return 0;
}
