#include "Math.h"


double Math::add(double addend, double addend2) {
    return addend + addend2;
}

double Math::sub(double minuend, double subtrahend) {
    return minuend - subtrahend;
}

double Math::multi(double multiplicand, double multiplicator) {
    return multiplicand * multiplicator;
}

double Math::devi(double dividend, double divisor) {
    if (divisor == 0) {
        return NAN;
    }
    return dividend / divisor;
}

double Math::pow(double base, double power) {
    return std::pow(base, power);
}

double Math::sqrt(double radicand) {
    if (radicand < 0) {
        return NAN;
    }
    return std::sqrt(radicand);
}

double Math::root(double radicand, double index) {
    if (radicand < 0 && static_cast<int>(index) % 2 == 0) {
        return NAN;
    }
    return std::pow(radicand, 1.0 / index);
}

double Math::abs(double value) {
    return value < 0 ? -value : value;
}

double Math::calculate(std::string expretion) {
    std::string expression = expretion;
    expression.erase(remove(expression.begin(), expression.end(), ' '), expression.end());
    char operators[5] = { '+', '-', '*', '/', '^' };

    for (char op : operators) {
        size_t pos = expression.find(op);
        if (pos != std::string::npos) {
            std::string left = expression.substr(0, pos);
            std::string right = expression.substr(pos + 1);

            // Convert operands to double
            double operand1 = std::stod(left);
            double operand2 = std::stod(right);

            switch (op) {
            case '+':
                return add(operand1, operand2);
            case '-':
                return sub(operand1, operand2);
            case '*':
                return multi(operand1, operand2);
            case '/':
                return devi(operand1, operand2);
            case '^':
                return pow(operand1, operand2);
            default:
                return NAN;
            }
        }
    }
    return NAN;
}