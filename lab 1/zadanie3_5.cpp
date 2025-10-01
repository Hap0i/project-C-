#include <iostream>
#include <cmath>

int numLen (long x) {
    if (x == 0) {
        return 0;
    }
    int i = 0;
    long n = std::abs(x);
    while (n > 0) {
        n /= 10;
        i++;
    }
    return i;
}

int main() {
    long x;
    std::cout << "Введите число x: ";
    std::cin >> x;
    int result = numLen(x);
    std:: cout << "Количество знаков в числе x: " << result << std::endl;
    return 0;
}