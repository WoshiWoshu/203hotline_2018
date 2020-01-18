/*
** EPITECH PROJECT, 2019
** displau
** File description:
** maths
*/

#include <cstring>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <chrono>
#include "law.hpp"

static cpp_int binomialCoeff(int n, int k)
{
    cpp_int binCoeff = 1;

    if (k > n - k)
        k = n - k;
    for (int i = 0; i < k; ++i) {
        binCoeff *= (n - i);
        binCoeff /= (i + 1);
    }
    return binCoeff;
}

void displayBinomialCoeff(char **av)
{
    std::cout << av[2] << "-combination of a 100 set:" << std::endl;
    std::cout << binomialCoeff(std::atof(av[1]), std::atof(av[2]))
              << std::endl;
}

void displayLaw(char **av, double (&law)(int d, int k))
{
    double lawVar = 0.0;
    double overload = 0.0;
    overload = 0.0;
    
    for (int i = 0; i < 100; ++i) {
        lawVar = law(std::stof(av[1]), i);
        if (i >= 26)
            overload += lawVar;
        if (i <= 50)
            std::cout << std::fixed << std::setprecision(3)
                      << i << " -> " << lawVar;
        if (i == 5 || i == 11 || i == 17 || i == 23
        || i == 29 || i == 35 || i == 41 || i == 47)
            std::cout << '\n';
        else if (i < 50)
            std::cout << '\t';
    }
    std::cout << std::fixed << std::setprecision(1)
    << "\noverload:  " << overload * 100 << "%" << std::endl;
}

double binomialLaw(int d, int k)
{
    double p = d / (8.0 * 3600.0);
    cpp_int binCoeff = binomialCoeff(3500, k);
    double binLaw =
    (double)binCoeff * (std::pow(p, k)) * (std::pow((1 - p), (3500 - k)));

    return binLaw;
}

double poissonLaw(int d, int k)
{
    cpp_int factK = 1;
    double lamb = 3500.0 * (d / (8.0 * 3600.0));
    double poisLaw = 0.0;

    for (int i = 1; i <= k; ++i) {
        factK *= i;
    }
    poisLaw = (std::exp(-lamb)) * (std::pow(lamb, k) / ((double)factK));
    return poisLaw;
}
