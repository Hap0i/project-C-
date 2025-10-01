#include <iostream>

bool isEqual(int a, int b, int c) {
    return (a == b == c);
}

int main() {
    int a, b, c;
    std::cout << "Ведите число a: ";
    std::cin >> a;
    std::cout << "Ведите число b: ";
    std::cin >> b;
    std::cout << "Ведите число c: ";
    std::cin >> c;
    bool result = isEqual(a, b, c);
    std::cout << std::boolalpha << "Результат: " << result << std::endl;
    return 0;
}