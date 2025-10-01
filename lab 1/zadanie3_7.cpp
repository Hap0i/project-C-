#include <iostream>

void square(int x) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            std::cout << '*';
        }
        std::cout << std::endl;
    }
}

int main() {
    int x;
    std::cout << "Введите размер квадрата: ";
    std::cin >> x;
    square(x);
    return 0;
}