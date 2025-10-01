#include <iostream>

bool isInRange(int a, int b, int num) {
    int min;
    if (a < b) {
        min = a;
    } 
    else {
        min = b;
    }
    int max;
    if (a > b) {
        max = a;
    } 
    else {
        max = b;
    }
    return num >= min && num <= max;
}

int main() {
    int a, b, num;
    std::cout << "Введите границу a: ";
    std::cin >> a;
    std::cout << "Введите границу b: ";
    std::cin >> b;
    std::cout << "Введите число для проверки: ";
    std::cin >> num;
    bool result = isInRange(a, b, num);
    std::cout << std::boolalpha << "Результат: " << result << std::endl;
    return 0;
}