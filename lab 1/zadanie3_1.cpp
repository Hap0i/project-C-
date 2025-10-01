#include <iostream>
#include <string>

std::string listNums(int x) {
    std::string result = "";
    int i = 0;
    while (i <= x) {
        result += std::to_string(i) + " ";
        i++;
    }
    return result;
}

int main() {
    int x;
    std::cout << "Введите число x: ";
    std::cin >> x;
    std::string result = listNums(x);
    std::cout << "Числа от 0 до " << x << ": " << result << std::endl;
    return 0;
}