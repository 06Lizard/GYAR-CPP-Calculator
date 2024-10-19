#include "Calculator.h"

double Calculator::calculate(const std::string& input) {
    std::cout << "Calculating expression: " << input << std::endl;
    std::string transformedInput = transformSymbols(input);
    std::cout << "Transformed expression: " << transformedInput << std::endl;
    return evaluateExpression(transformedInput);
}

std::string Calculator::transformSymbols(const std::string& input) {
    std::string modifiedInput = input;
    handleParentheses(modifiedInput);
    handleExponents(modifiedInput); // Handle exponentiation
    return modifiedInput;
}

void Calculator::handleParentheses(std::string& expression) {
    while (expression.find('(') != std::string::npos) {
        size_t openParenIndex = expression.rfind('(');
        size_t closeParenIndex = expression.find(')', openParenIndex);

        if (openParenIndex != std::string::npos && closeParenIndex != std::string::npos) {
            std::string innerExpression = expression.substr(openParenIndex + 1, closeParenIndex - openParenIndex - 1);
            std::cout << "Evaluating inner expression: " << innerExpression << std::endl;
            double result = evaluateExpression(innerExpression);
            expression.replace(openParenIndex, closeParenIndex - openParenIndex + 1, std::to_string(result));
            std::cout << "Result of parentheses: " << result << std::endl;
        }
        else {
            throw std::invalid_argument("Mismatched parentheses.");
        }
    }
}

void Calculator::handleExponents(std::string& expression) {
    // Handle exponentiation
    while (expression.find('^') != std::string::npos) {
        size_t index = expression.find('^');

        // Extract left operand
        std::string leftStr = trim(expression.substr(0, index));
        std::cout << "Left Operand (before parse): " << leftStr << std::endl;
        if (leftStr.empty()) {
            throw std::invalid_argument("Left operand for exponentiation is missing.");
        }
        double left = parseNumber(leftStr);
        std::cout << "Left Operand (parsed): " << left << std::endl;

        // Extract right operand, skipping spaces
        size_t rightStart = index + 1;
        size_t rightEnd = rightStart;

        // Move rightEnd to find the next operator or end of string, while skipping spaces
        while (rightEnd < expression.length() && expression[rightEnd] == ' ') {
            ++rightEnd; // Skip spaces
        }
        while (rightEnd < expression.length() && expression[rightEnd] != ' ' &&
            expression[rightEnd] != '+' && expression[rightEnd] != '-' &&
            expression[rightEnd] != '*' && expression[rightEnd] != '/' &&
            expression[rightEnd] != ')') {
            ++rightEnd; // Continue until we hit a space or an operator
        }

        std::string rightStr = trim(expression.substr(index + 1, rightEnd - (index + 1)));
        std::cout << "Right Operand (before parse): " << rightStr << std::endl;
        if (rightStr.empty()) {
            throw std::invalid_argument("Right operand for exponentiation is missing.");
        }

        double right = parseNumber(rightStr);
        std::cout << "Right Operand (parsed): " << right << std::endl;

        // Replace exponentiation expression with the result
        double result = Math::pow(left, right);
        std::cout << "Result of exponentiation: " << result << std::endl;

        // Replace the exponentiation expression with the result
        expression.replace(0, rightEnd, std::to_string(result));
        std::cout << "Updated expression after exponentiation: " << expression << std::endl;
    }
}

double Calculator::evaluateExpression(const std::string& expression) {
    std::cout << "Evaluating expression: " << expression << std::endl;

    // Handle exponentiation first
    std::string expExpression = expression;
    handleExponents(expExpression);
    //handleRoots
    //handleMulti
    //handleDiv


    std::istringstream stream(expExpression);
    double left;
    char op;

    stream >> left;
    std::cout << "Initial Left Operand: " << left << std::endl;

    while (stream >> op) {
        std::cout << "Current Operator: " << op << std::endl;
        double right;
        stream >> right;
        std::cout << "Next Right Operand: " << right << std::endl;
        left = applyOperation(left, right, op);
        std::cout << "Result after applying operation: " << left << std::endl;
    }

    return left;
}

double Calculator::applyOperation(double left, double right, char op) {
    std::cout << "Applying operation: " << left << " " << op << " " << right << std::endl;
    switch (op) {
    case '+':
        return Math::add(left, right);
    case '-':
        return Math::sub(left, right);
    case '*':
        return Math::multi(left, right);
    case '/':
        return Math::devi(left, right);
    default:
        throw std::invalid_argument("Invalid operator: " + std::string(1, op));
    }
}

double Calculator::parseNumber(const std::string& str) {
    if (str.empty()) {
        throw std::invalid_argument("Empty string provided to parseNumber.");
    }
    std::cout << "Parsing number from string: " << str << std::endl;
    return std::stod(str);
}

// Utility function to trim whitespace
std::string Calculator::trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    if (first == std::string::npos || last == std::string::npos) {
        return ""; // Return an empty string if no valid characters found
    }
    return str.substr(first, (last - first + 1));
}