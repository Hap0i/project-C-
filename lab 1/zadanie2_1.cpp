#include <iostream>

int abs (int x) {
    if (x < 0) {
        return -x;
    }
    else {
        return x;
    }
}

int main() {
    int x;
    std::cout << "Введите число x: ";
    std::cin >> x;
    int result = abs(x);
    std::cout << "Результат: " << result << std::endl;
    return 0;
}