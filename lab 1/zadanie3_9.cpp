#include <iostream>

void rightTriangle(int x) {
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < x - i; j++) {
            std::cout << ' ';
        }
        for (int j = 0; j < i; j++) {
            std::cout << '*';
        }
        std::cout << std::endl;
    }
}

int main() {
    int x;
    std::cout << "Введите высоту треугольника: ";
    std::cin >> x;
    rightTriangle(x);
    return 0;
}
