#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <fstream>
#include <string>
#include <limits>
#include <locale>
#include <cstdlib>

// Функция для ввода числа с проверкой
int inputNumber(const std::string& prompt) {
    int value = 0;
    std::cout << prompt;
    while (!(std::cin >> value)) {
        std::cout << "Ошибка! Введите целое число: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return value;
}

// Задание 1
void task1() {
    std::cout << "\n=== ЗАДАНИЕ 1 ===" << std::endl;
    
    std::vector<int> V;
    std::deque<int> D;
    std::list<int> L;
    
    // Ввод вектора
    std::cout << "Для вектора V:" << std::endl;
    int n = 0;
    do {
        n = inputNumber("Введите количество элементов (четное, >= 2): ");
    } while (n < 2 || n % 2 != 0);
    
    for (int i = 0; i < n; i++) {
        V.push_back(inputNumber("Введите число: "));
    }
    
    // Ввод дека
    std::cout << "\nДля дека D:" << std::endl;
    do {
        n = inputNumber("Введите количество элементов (четное, >= 2): ");
    } while (n < 2 || n % 2 != 0);
    
    for (int i = 0; i < n; i++) {
        D.push_back(inputNumber("Введите число: "));
    }
    
    // Ввод списка
    std::cout << "\nДля списка L:" << std::endl;
    do {
        n = inputNumber("Введите количество элементов (четное, >= 2): ");
    } while (n < 2 || n % 2 != 0);
    
    for (int i = 0; i < n; i++) {
        L.push_back(inputNumber("Введите число: "));
    }
    
    // Обмен средних элементов в векторе
    auto v1 = V.begin();
    std::advance(v1, V.size() / 2 - 1);
    auto v2 = V.begin();
    std::advance(v2, V.size() / 2);
    std::swap(*v1, *v2);
    
    // Обмен средних элементов в деке
    auto d1 = D.begin();
    std::advance(d1, D.size() / 2 - 1);
    auto d2 = D.begin();
    std::advance(d2, D.size() / 2);
    std::swap(*d1, *d2);
    
    // Обмен средних элементов в списке
    auto l1 = L.begin();
    std::advance(l1, L.size() / 2 - 1);
    auto l2 = L.begin();
    std::advance(l2, L.size() / 2);
    std::swap(*l1, *l2);
    
    // Вывод результатов
    std::cout << "\nРезультаты:" << std::endl;
    
    std::cout << "Вектор V: ";
    for (auto it = V.begin(); it != V.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Дек D: ";
    for (auto it = D.begin(); it != D.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Список L: ";
    for (auto it = L.begin(); it != L.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// Задание 2
void task2() {
    std::cout << "\n=== ЗАДАНИЕ 2 ===" << std::endl;
    
    std::deque<int> D;
    
    int n = 0;
    do {
        n = inputNumber("Введите количество элементов для дека (нечетное, >= 5): ");
    } while (n < 5 || n % 2 == 0);
    
    for (int i = 0; i < n; i++) {
        D.push_back(inputNumber("Введите число: "));
    }
    
    // Находим 5 средних элементов
    int start = n / 2 - 2;
    int end = n / 2 + 3;
    
    // Добавляем в начало
    D.insert(D.begin(), D.begin() + start, D.begin() + end);
    
    std::cout << "Результат: ";
    for (auto it = D.begin(); it != D.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// Задание 3
void task3() {
    std::cout << "\n=== ЗАДАНИЕ 3 ===" << std::endl;
    
    std::list<int> L;
    
    int n = 0;
    do {
        n = inputNumber("Введите количество элементов для списка (четное): ");
    } while (n % 2 != 0);
    
    for (int i = 0; i < n; i++) {
        L.push_back(inputNumber("Введите число: "));
    }
    
    auto i = L.begin();
    auto r = L.end();
    r--;
    
    for (int count = 0; count < n / 2; count++) {
        L.splice(i, L, r);
        i++;
        r--;
    }
    
    std::cout << "Результат: ";
    for (auto it = L.begin(); it != L.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// Задание 4
void task4() {
    std::cout << "\n=== ЗАДАНИЕ 4 ===" << std::endl;
    
    std::string filename;
    std::cout << "Введите имя файла: ";
    std::cin >> filename;
    
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Ошибка открытия файла!" << std::endl;
        return;
    }
    
    std::cout << "Числа с нечетными номерами: ";
    
    int counter = 0;
    int number = 0;
    while (file >> number) {
        counter++;
        if (counter % 2 == 1) {
            std::cout << number << " ";
        }
    }
    
    std::cout << std::endl;
    file.close();
}

// Задание 5
void task5() {
    std::cout << "\n=== ЗАДАНИЕ 5 ===" << std::endl;
    
    std::vector<int> V;
    int n = inputNumber("Введите количество элементов для вектора: ");
    
    for (int i = 0; i < n; i++) {
        V.push_back(inputNumber("Введите число: "));
    }
    
    // Ищем нулевые элементы
    int zeroCount = 0;
    int secondZeroIndex = -1;
    
    for (int i = 0; i < V.size(); i++) {
        if (V[i] == 0) {
            zeroCount++;
            if (zeroCount == 2) {
                secondZeroIndex = i;
                break;
            }
        }
    }
    
    if (secondZeroIndex != -1) {
        V.erase(V.begin() + secondZeroIndex);
        std::cout << "Второй нулевой элемент удален" << std::endl;
    } else {
        std::cout << "Второй нулевой элемент не найден" << std::endl;
    }
    
    std::cout << "Результат: ";
    for (int num : V) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Задание 6
void task6() {
    std::cout << "\n=== ЗАДАНИЕ 6 ===" << std::endl;
    
    std::vector<int> V;
    
    int n = 0;
    do {
        n = inputNumber("Введите количество элементов для вектора (четное): ");
    } while (n % 2 != 0);
    
    for (int i = 0; i < n; i++) {
        V.push_back(inputNumber("Введите число: "));
    }
    
    // Первая половина - заменяем отрицательные на -1
    for (int i = 0; i < n / 2; i++) {
        if (V[i] < 0) {
            V[i] = -1;
        }
    }
    
    // Вторая половина - заменяем положительные на 1
    for (int i = n / 2; i < n; i++) {
        if (V[i] > 0) {
            V[i] = 1;
        }
    }
    
    std::cout << "Результат: ";
    for (int num : V) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Задание 7
void task7() {
    std::cout << "\n=== ЗАДАНИЕ 7 ===" << std::endl;
    
    std::list<int> L;
    int n = inputNumber("Введите количество элементов для списка: ");
    
    for (int i = 0; i < n; i++) {
        L.push_back(inputNumber("Введите число: "));
    }
    
    // Создаем три списка для разных типов чисел
    std::list<int> negative, zero, positive;
    
    for (int num : L) {
        if (num < 0) {
            negative.push_back(num);
        } else if (num == 0) {
            zero.push_back(num);
        } else {
            positive.push_back(num);
        }
    }
    
    // Объединяем списки
    L.clear();
    L.splice(L.end(), negative);
    L.splice(L.end(), zero);
    L.splice(L.end(), positive);
    
    std::cout << "Результат: ";
    for (int num : L) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Задание 8
void task8() {
    std::cout << "\n=== ЗАДАНИЕ 8 ===" << std::endl;
    
    std::list<int> L;
    int n = inputNumber("Введите количество элементов для списка: ");
    
    for (int i = 0; i < n; i++) {
        L.push_back(inputNumber("Введите число: "));
    }
    
    std::vector<double> V;
    
    // Вычисляем средние арифметические соседних элементов
    auto it1 = L.begin();
    auto it2 = L.begin();
    it2++;
    
    while (it2 != L.end()) {
        double average = (*it1 + *it2) / 2.0;
        V.push_back(average);
        it1++;
        it2++;
    }
    
    std::cout << "Средние арифметические: ";
    for (double num : V) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Главная функция
int main() {
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
    
    std::cout << "ЛАБОРАТОРНАЯ РАБОТА ПО STL" << std::endl;
    std::cout << "==========================" << std::endl;
    
    while (true) {
        std::cout << "\nВыберите задание (1-8) или 0 для выхода: ";
        int choice = 0;
        std::cin >> choice;
        
        if (choice == 0) {
            break;
        }
        
        switch (choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            case 5: task5(); break;
            case 6: task6(); break;
            case 7: task7(); break;
            case 8: task8(); break;
            default: std::cout << "Неверный выбор!" << std::endl;
        }
    }
    
    std::cout << "Программа завершена." << std::endl;
    return 0;
}
