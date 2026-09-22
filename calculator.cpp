#include "calculator.h"

#include <iostream>
#include <format>
#include <cmath>

Number Plus(Number a, Number b) {
    return a + b;
}

Number Minus(Number a, Number b) {
    return a - b;
}

Number Multiply(Number a, Number b) {
    return a * b;
}

Number Divide(Number a, Number b) {
    return a / b;
}

Number Degree(Number a, Number b) {
    return std::pow(a, b);
}

void SaveMemory(Number number, Number& mem) {
    mem = number;
}

void LoadMemory(Number& number, Number mem) {
    number = mem;
}

void printResult(Number number) {
    std::cout << number << std::endl;
}

bool ReadNumber(Number& result) {
    std::string tmp;
    std::cin >> tmp;
    try {
        result = std::stod(tmp);
        return true;
    } catch (...) {
        std::cerr << "Error: Numeric operand expected" << std::endl;
        return false;
    }
}

bool ReadNumber(Number& result, std::string str) {
    try {
        result = std::stod(str);
        return true;
    } catch (...) {
        std::cerr << "Error: Numeric operand expected" << std::endl;
        return false;
    }
}



bool RunCalculatorCycle() {
    Number number, mem, tmpNumber;
    bool isMemoryEmpty = true;

    if (!ReadNumber(number)) return false;

    std::string tmp, tmp2;
    for (;true;) {
        std::cin >> tmp;
        if (tmp == "q") {
            return true;
        }
        else if (tmp == "+" ||
                tmp == "-" ||
                tmp == "*" ||
                tmp == "/" ||
                tmp == ":" ||
                tmp == "**") {
            std::cin >> tmp2;
            if (!ReadNumber(tmpNumber, tmp2)) {
                return false;
            }
            
            if (tmp == "+") number = Plus(number, tmpNumber);
            else if (tmp == "-") number = Minus(number, tmpNumber);
            else if (tmp == "*") number = Multiply(number, tmpNumber);
            else if (tmp == "/") number = Divide(number, tmpNumber);
            else if (tmp == "**") number = Degree(number, tmpNumber);
            else number = tmpNumber;
        }
        else if (tmp == "=") {
            printResult(number);
        }
        else if (tmp == "c") {
            number = 0;
        }
        else if (tmp == "s") {
            SaveMemory(number, mem);
            isMemoryEmpty = false;            
        }
        else if (tmp == "l") {
            if (!isMemoryEmpty) {
                LoadMemory(number, mem);
            }
            else {
                std::cerr << "Error: Memory is empty" << std::endl;
                return false;
            }
        }
        else {
            std::cerr << "Error: Unknown token " << tmp << std::endl;
            return false;
        }
    }
    return false;
}