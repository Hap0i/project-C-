#include <iostream>

int charToNum(char x) {
    return x - '0';
}

int main() {
    char digit;
    std::cout << "Введите символ цифры (0-9): ";
    std::cin >> digit;
    int result = charToNum(digit);
    std::cout << "Числовое значение символа '" << digit << "' = " << result << std::endl;
    return 0;
}