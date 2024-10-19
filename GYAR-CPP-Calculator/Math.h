#pragma once
#include <cmath>
#include <string>
#include <sstream>
#include <stdexcept>
#include <map>
#include <functional>

class Math
{
public:

    static double add(double addend, double addend2);
    static double sub(double minuend, double subtrahend);
    static double multi(double multiplicand, double multiplicator);
    static double devi(double dividend, double divisor);
    static double pow(double base, double power);
    static double sqrt(double radicand);
    static double root(double radicand, double index);
    static double abs(double value);
    static double calculate(std::string expretion);
};