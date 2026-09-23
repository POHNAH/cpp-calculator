#include "calculator.h"

#include <string>
#include <iostream>
#include <format>
#include <cmath>

Number DoPlus(Number a, Number b) {
    return a + b;
}

Number DoMinus(Number a, Number b) {
    return a - b;
}

Number DoMultiply(Number a, Number b) {
    return a * b;
}

Number DoDivide(Number a, Number b) {
    return a / b;
}

Number DoDegree(Number a, Number b) {
    return std::pow(a, b);
}

void SaveMemory(Number number, Number& mem) {
    mem = number;
}

void LoadMemory(Number& number, Number mem) {
    number = mem;
}

void PrintResult(Number number) {
    std::cout << number << std::endl;
}

// Возвращает true, если удалось прочитать число
// и сохранить его в Number.
bool ReadNumber(Number& result) {
    std::string buff_str;
    std::cin >> buff_str;
    try {
        result = std::stod(buff_str);
        return true;
    } catch (...) {
        std::cerr << "Error: Numeric operand expected" << std::endl;
        return false;
    }
}

// Возвращает true, если удалось прочитать число из строки str
// и сохранить его в Number.
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
    Number number = 0;
    Number mem = 0;
    Number tmp_number = 0;
    bool is_memory_empty = true;

    if (!ReadNumber(number)) {
        return false;
    }

    std::string buff_str;
    std::string buff_str2;
    for (;true;) {
        std::cin >> buff_str;
        if (buff_str == "q") {
            return true;
        }
        else if (buff_str == "+" ||
                buff_str == "-" ||
                buff_str == "*" ||
                buff_str == "/" ||
                buff_str == ":" ||
                buff_str == "**") {
            std::cin >> buff_str2;
            if (!ReadNumber(tmp_number, buff_str2)) {
                return false;
            }
            
            if (buff_str == "+") {
                number = DoPlus(number, tmp_number);
            }
            else if (buff_str == "-") {
                number = DoMinus(number, tmp_number);
            }
            else if (buff_str == "*") {
                number = DoMultiply(number, tmp_number);
            }
            else if (buff_str == "/") {
                number = DoDivide(number, tmp_number);
            }
            else if (buff_str == "**") {
                number = DoDegree(number, tmp_number);
            }
            else {
                number = tmp_number;
            }
        }
        else if (buff_str == "=") {
            printResult(number);
        }
        else if (buff_str == "c") {
            number = 0;
        }
        else if (buff_str == "s") {
            SaveMemory(number, mem);
            is_memory_empty = false;            
        }
        else if (buff_str == "l") {
            if (!is_memory_empty) {
                LoadMemory(number, mem);
            }
            else {
                std::cerr << "Error: Memory is empty" << std::endl;
                return false;
            }
        }
        else {
            std::cerr << "Error: Unknown token " << buff_str << std::endl;
            return false;
        }
    }
    return false;
}