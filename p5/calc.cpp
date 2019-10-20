#include "dlist.h"
#include <iostream>
using namespace std;


template<typename T>
void twoOperand(char c, Dlist<T> &stack) {
// Requirement: command 'c' asks for two operands
// MODIFIES: stack
// EFFECTS: Pop the top two numbers off the 'stack' and do operations according to 'c'.
//          throws an instance of emptyList if 'stack' doesn't have enough numbers.
    auto a = new T;
    auto b = new T;
    try {
        *a = *stack.removeBack();
    }
    catch (emptyList) {
        throw;
    }
    try {
        *b = *stack.removeBack();
    }
    catch (emptyList) {
        stack.insertBack(a);
        throw;
    }
    bool divideFail = false;
    switch (c) {
        case '+':
            *b = *b + *a;
            delete a;
            break;
        case '-':
            *b = *b - *a;
            delete a;
            break;
        case '*':
            *b = *b * *a;
            delete a;
            break;
        case '/':
            if (*a == 0) {
                std::cout << "Divide by zero\n";
                divideFail = true;
                break;
            }
            else {
                *b = *b / *a;
                delete a;
                break;
            }
        case 'r':
            stack.insertBack(a);
            break;
        default:
            break;
    }
    stack.insertBack(b);
    if (divideFail) stack.insertBack(a);
}

template<typename T>
void oneOperand(char c, Dlist<T> &stack) {
// Requirement: command 'c' asks for one operand
// MODIFIES: stack
// EFFECTS: Pop the top two numbers off the 'stack' and do operations according to 'c'.
//          throws an instance of emptyList if 'stack' doesn't have enough numbers.
    auto a = new T;
    try {
        *a = *stack.removeBack();
    }
    catch (emptyList) {
        throw;
    }
    switch (c) {
        case 'n':
            *a = - *a;
            break;
        case 'd':
            stack.insertBack(a);
            break;
        case 'p':
            std::cout << *a << std::endl;
            break;
        default:
            break;
    }
    stack.insertBack(a);
}

template<typename T>
void printAll(Dlist<T> &stack) {
    Dlist<T> tmp;
    tmp.operator=(stack);
    while (!tmp.isEmpty()) {
        auto top = tmp.removeBack();
        std::cout << *top  << " ";
        delete top;
    }
    std::cout << std::endl;
}

template<typename T>
void clear(Dlist<T> stack) {
    while (!stack.isEmpty()) {
        delete stack.removeBack();
    }
}

template<typename T>
bool run(std::string input, Dlist<T> &stack) {
    if (input.length() == 1) {
        try {
            switch (input[0]) {
                case '+':
                case '-':
                case '*':
                case '/':
                case 'r':
                    twoOperand(input[0], stack);
                    return true;
                case 'n':
                case 'd':
                case 'p':
                    oneOperand(input[0], stack);
                    return true;
                case 'c':
                    clear(stack);
                    return true;
                case 'a':
                    printAll(stack);
                    return true;
                case 'q':
                    return false;
                default:
                    if (input[0] < '0' || input[0] > '9') {
                        std::cout << "Bad input\n";
                        return true;
                    }
            }
        }
        catch (emptyList) {
            std::cout << "Not enough operands\n";
            return true;
        }
    }
    if (input.length() > 1) {
        if (input[0] != '-' && (input[0] < '0' || input[0] > '9')) {
            std::cout << "Bad input\n";
            return true;
        }
        for (unsigned int i = 1; i < input.length(); i++) {
            if (input[i] < '0' || input[i] > '9') {
                std::cout << "Bad input\n";
                return true;
            }
        }
    }
    char *end;
//    int target = std::strtol(input.c_str(), &end, 10);
    int number = std::strtol(input.c_str(), &end, 10);
    auto target = new T;
    *target = number;
    stack.insertBack(target);
    return true;
}


int main ( ){
    std::string str;
    Dlist<int> stack;
    do {
        std::cin >> str;
    } while (run(str, stack));
    return 0;
}