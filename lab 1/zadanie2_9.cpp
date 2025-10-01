#include <iostream>

std::string day (int x) {
    switch(x) {
        case 1: return "Понедельник";
        break;
        case 2: return "Вторник";
        break;
        case 3: return "Среда";
        break;
        case 4: return "Четверг";
        break;
        case 5: return "Пятница";
        break;
        case 6: return "Суббота";
        break;
        case 7: return "Воскресенье";
        break;
        default: return "это не день недели";
        break;
    }
    return 0;
}

int main() {
    int x;
    std::cout << "Введите номер дня недели (1-7): ";
    std::cin >> x;
    std::string result = day(x);
    std::cout << "Результат: " << result << std::endl;
    return 0;
}