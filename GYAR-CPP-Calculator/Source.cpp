#include "Math.h"
#include "ExpressionEvaluator.h"// dosn't quite work yet
#include <iostream>

int math() {
    while (true) {
        std::cout << "Input format : val1 op val2, e.g., 2 * 4\nOperators : +, -, *, / , ^\nEnter a mathematical expression : ";
        std::string exp;
        std::cin >> exp;
        std::cout << Math::calculate(exp) << "\n";
    }
}

int main() {
    math();


    // trying to make calculator
    try {
        Calculator calculator;
        std::string expression = "3 + 5 * (2 ^ 3)";  // Example input
        double result = calculator.calculate(expression);
        std::cout << "Result: " << result << std::endl; // Output: Result: 43
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}