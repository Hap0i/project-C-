#include <iostream>

bool is2Digits(int x) {
    return (x >= 10 && x <= 99) || (x <= -10 && x >= -99);
}

int main() {
    int number;
    std::cout << "Введите число: ";
    std::cin >> number;
    bool result = is2Digits(number);
    std::cout << std::boolalpha << result << std::endl;
    return 0;
}