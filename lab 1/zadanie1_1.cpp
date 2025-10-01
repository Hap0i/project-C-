#include <iostream>
#include <cmath>

double fraction(double x) {
    return x - std::floor(x);
}

int main() {
    double number;
    std::cout << "Введите число: ";
    std::cin >> number;
    double result = fraction(number);
    std::cout << "Дробная часть числа " << number << " = " << result << std::endl;
    return 0;
}