#include <iostream>

int sum2(int x, int y) {
    int sum = x + y;
    if (sum >= 10 && sum <= 19) {
        return 20;
    }
    return sum;
}

int main() {
    int x, y;
    std::cout << "Введите первое число: ";
    std::cin >> x;
    std::cout << "Введите второе число: ";
    std::cin >> y;
    int result = sum2(x, y);
    std::cout << "Результат: " << result << std::endl;
    return 0;
}