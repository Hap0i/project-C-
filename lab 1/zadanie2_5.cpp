#include <iostream>

int max3(int x, int y, int z) {
    int max = x;
    if (y > max) {
        max = y;
    }
    if (z > max) {
        max = z;
    }
    return max;
}

int main() {
    int x, y, z;
    std::cout << "Введите первое число: ";
    std::cin >> x;
    std::cout << "Введите второе число: ";
    std::cin >> y;
    std::cout << "Введите третье число: ";
    std::cin >> z;
    int result = max3(x, y, z);
    std::cout << "Максимальное число: " << result << std::endl;
    return 0;
}