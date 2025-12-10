#include "lab5.h"
#include <iostream>
#include <ctime>
#include <locale>
#include <cstdlib>

int main() {
    // Установка русской кодировки
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
    
    // Инициализация генератора случайных чисел
    srand(time(nullptr));
    
    // Вызов всех заданий
    FileTasks::zadanie1();
    FileTasks::zadanie2();
    FileTasks::zadanie3();
    FileTasks::zadanie4();
    FileTasks::zadanie5();
    FileTasks::zadanie6();
    
    return 0;
}