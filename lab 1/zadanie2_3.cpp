#include <iostream>

bool is35(int x) {
    bool del3 = (x % 3 == 0);
    bool del5 = (x % 5 == 0);
    return (del3 || del5) && !(del3 && del5);
}

int main() {
    int x;
    std::cout << "Введите число: ";
    std::cin >> x;
    bool result = is35(x);
    std::cout << std::boolalpha << "Результат: " << result << std::endl;
    return 0;
}