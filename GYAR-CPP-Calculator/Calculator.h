#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <cctype>
#include <algorithm>
#include "Math.h"

class Calculator {
public:
    double calculate(const std::string& input);

private:
    std::string transformSymbols(const std::string& input);
    double evaluateExpression(const std::string& expression);
    double applyOperation(double left, double right, char op);
    double parseNumber(const std::string& str);
    void handleParentheses(std::string& expression);
    void handleExponents(std::string& expression);
    std::string trim(const std::string& str);
};