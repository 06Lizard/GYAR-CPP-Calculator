#pragma once
#include "Calculator.h"

class ExpressionEvaluator {
public:
    static std::string currentAnswer;
    static void calculate(const std::string& input);
};

