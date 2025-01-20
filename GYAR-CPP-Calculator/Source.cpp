#include "Math.h"
#include <iostream>
#include <chrono>

int main() {
    while (true) {
        using clock = std::chrono::high_resolution_clock; // cleans up the timers

        std::cout << "Input format : val1 op val2, e.g., 2 * 4\nOperators : +, -, *, / , ^\nEnter a mathematical expression : ";
        std::string exp; // init variable
        std::cin >> exp; // get input

        auto start = clock::now(); // start timer

        double ans = Math::calculate(exp); // the calculation

        auto end = clock::now(); // end timer
        std::chrono::duration<double, std::micro> duration = end - start;
        std::cout << "\t" << exp << " = " << ans << "\n\t"
        //  << "Calculation took: "
            << duration.count() << " microseconds\n" << std::endl;
    }
}