#include <iostream>
#include <cstdlib>
#include <locale>
#include "lab4.h"

int main() {
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
    
    // Тест конструкторов
    std::cout << "1. Конструкторы:\n";
    Time t1 = inputTime();
    Time t2;
    Time t3 = t1;
    std::cout << "t1: " << t1 << "\nt2: " << t2 << "\nt3: " << t3 << "\n\n";

    // Тест метода addMinutes
    std::cout << "2. Метод addMinutes:\n";
    unsigned int min;
    std::cout << "Минуты для добавления: ";
    std::cin >> min;
    std::cout << t1 << " + " << min << " мин = " << t1.addMinutes(min) << "\n\n";

    // Тест унарных операций
    std::cout << "3. Унарные операции:\n";
    Time t4 = t1;
    std::cout << "Исходное: " << t4 << "\n";
    std::cout << "++t: " << ++t4 << "\n";
    std::cout << "t++: " << t4++ << " (после: " << t4 << ")\n";
    std::cout << "--t: " << --t4 << "\n";
    std::cout << "t--: " << t4-- << " (после: " << t4 << ")\n\n";

    // Тест приведения типа
    std::cout << "4. Приведение типа:\n";
    std::cout << "short(t1): " << (short)t1 << "\n";
    std::cout << "bool(t1): " << (t1 ? "true" : "false") << "\n";
    std::cout << "bool(00:00): " << (Time(0,0) ? "true" : "false") << "\n\n";

    // Тест бинарных операций
    std::cout << "5. Бинарные операции:\n";
    std::cout << "Минуты для операций: ";
    std::cin >> min;
    std::cout << t1 << " + " << min << " = " << t1 + min << "\n";
    std::cout << t1 << " - " << min << " = " << t1 - min << "\n";

    return 0;
}