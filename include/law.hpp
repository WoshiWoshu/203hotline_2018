/*
** EPITECH PROJECT, 2019
** law.hpp
** File description:
** maths
*/

#pragma once

#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;

extern double poissonLaw(int d, int k);
extern double binomialLaw(int d, int k);
extern void displayBinomialCoeff(char **av);
extern void displayLaw(char **av, double (&law)(int d, int k));
