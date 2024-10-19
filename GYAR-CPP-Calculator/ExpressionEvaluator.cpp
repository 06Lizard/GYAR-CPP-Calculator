#include "ExpressionEvaluator.h"

std::string ExpressionEvaluator::currentAnswer;

void ExpressionEvaluator::calculate(const std::string& input) {
    Calculator calculator;
    try {
        double result = calculator.calculate(input);
        currentAnswer = std::to_string(result);
    }
    catch (const std::exception& e) {
        currentAnswer = "Error: " + std::string(e.what());
    }
}