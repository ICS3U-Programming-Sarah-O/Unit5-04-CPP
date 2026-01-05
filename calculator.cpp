// Copyright (c) 2025 Sarah OUAMOU. All rights reserved.
//
// Created by: Sarah OUAMOU
// Date: 12-18-2025
// This program performs basic arithmetic operations.

#include <iostream>
#include <string>

double Calculate(char sign, double first_number, double second_number) {
    if (sign == '+') {
        return first_number + second_number;
    } else if (sign == '-') {
        return first_number - second_number;
    } else if (sign == '*') {
        return first_number * second_number;
    } else if (sign == '/') {
        return first_number / second_number;
    }
    return 0.0;  // Required to satisfy all control paths
}

int main() {
    char sign;
    std::string input;
    double first_number;
    double second_number;

    while (true) {
        std::cout << "Enter operation (+, -, *, /): ";
        std::cin >> sign;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Please try again.\n\n";
            continue;
        }

        if (sign != '+' && sign != '-' && sign != '*' && sign != '/') {
            std::cout << "Invalid operation. Please try again.\n\n";
            continue;
        }

        try {
            std::cout << "Enter first number: ";
            std::cin >> input;
            first_number = std::stod(input);

            std::cout << "Enter second number: ";
            std::cin >> input;
            second_number = std::stod(input);
        } catch (...) {
            std::cout << "Invalid number entered.\n\n";
            continue;
        }

        if (sign == '/' && second_number == 0) {
            std::cout << "Error: Division by zero is not allowed.\n\n";
            continue;
        }

        double result = Calculate(sign, first_number, second_number);
        std::cout << "\nResult: " << first_number << " " << sign << " "
                  << second_number << " = " << result << std::endl;
        break;
    }
}
