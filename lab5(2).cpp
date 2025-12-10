#include "lab5.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <cstring>
#include <locale>
#include <cstdlib>
#include <cmath>

// Задание 1
void FileTasks::zadanie1() {
    std::cout << "=== ЗАДАНИЕ 1 ===" << std::endl;
    
    // Бинарный файл 
    std::ofstream source_file("task1(1).bin", std::ios::binary);
    int numbers[10];
    
    std::cout << "Исходные числа: ";
    for (int i = 0; i < 10; i++) {
        numbers[i] = 1 + rand() % 100;
        source_file.write((char*)&numbers[i], sizeof(numbers[i]));
        std::cout << numbers[i] << " ";
    }
    source_file.close();
    std::cout << std::endl;
    
    // Читаем и находим четные
    std::ifstream read_file("task1(1).bin", std::ios::binary);
    std::ofstream even_file("task1(2).bin", std::ios::binary);
    
    std::vector<int> even_numbers;
    int num = 0;
    
    while (read_file.read((char*)&num, sizeof(num))) {
        if (num % 2 == 0) {
            even_numbers.push_back(num);
            even_file.write((char*)&num, sizeof(num));
        }
    }
    read_file.close();
    even_file.close();
    
    // Выводим результат
    std::cout << "Четные числа: ";
    for (int n : even_numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Найдено четных чисел: " << even_numbers.size() << std::endl;
    std::cout << "Файлы созданы: task1(1).bin, task1(2).bin" << std::endl;

    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
}

// Задание 2
void FileTasks::zadanie2() {
    std::cout << "\n=== ЗАДАНИЕ 2 ===" << std::endl;
    
    std::ofstream file("task2.bin", std::ios::binary);
    for (int i = 0; i < 8; i++) {
        int num = 1 + rand() % 100;
        file.write((char*)&num, sizeof(num));
    }
    file.close();
    
    std::ifstream in("task2.bin", std::ios::binary);
    int nums[9];
    int count = 0;
    
    while (in.read((char*)&nums[count], sizeof(int)) && count < 9) {
        count++;
    }
    in.close();
    
    // Заполнение матрицы
    int matrix[3][3];
    int index = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (index < count) {
                matrix[i][j] = nums[index++];
            } else {
                matrix[i][j] = 0;
            }
        }
    }
    
    std::cout << "Исходная матрица:" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    
    // Меняем min и max
    for (int i = 0; i < 3; i++) {
        int min_idx = 0, max_idx = 0;
        for (int j = 1; j < 3; j++) {
            if (matrix[i][j] < matrix[i][min_idx]) min_idx = j;
            if (matrix[i][j] > matrix[i][max_idx]) max_idx = j;
        }
        int temp = matrix[i][min_idx];
        matrix[i][min_idx] = matrix[i][max_idx];
        matrix[i][max_idx] = temp;
    }
    
    std::cout << "\nПосле замены:" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
}

// Задание 3
void FileTasks::zadanie3() {
    std::cout << "\n=== ЗАДАНИЕ 3 ===" << std::endl;
    
    // Файл с багажом 3 пассажиров
    std::ofstream out("task3.bin", std::ios::binary);
    
    std::cout << "Исходные данные о багаже:" << std::endl;
    
    for (int p = 0; p < 3; p++) {
        int items = 2 + rand() % 3; // 2-4 вещи
        out.write((char*)&items, sizeof(int));
        
        std::cout << "\nПассажир " << p + 1 << " (" << items << " вещей):" << std::endl;
        
        for (int i = 0; i < items; i++) {
            Baggage item;
            const char* names[] = {"Чемодан", "Сумка", "Рюкзак", "Коробка"};
            strcpy(item.name, names[rand() % 4]);
            item.weight = 1.0 + (rand() % 300) / 10.0;
            out.write((char*)&item, sizeof(Baggage));
            
            std::cout << "  " << item.name << ": " << item.weight << " кг" << std::endl;
        }
    }
    out.close();
    
    std::cout << "\nАнализ данных из файла:" << std::endl;
    
    std::ifstream in("task3.bin", std::ios::binary);
    double total_weight = 0;
    int total_items = 0;
    std::vector<double> avg_weights;
    
    int passenger_num = 0;
    while (!in.eof()) {
        int items = 0;
        if (!in.read((char*)&items, sizeof(int))) break;
        
        double passenger_weight = 0;
        for (int i = 0; i < items; i++) {
            Baggage item;
            in.read((char*)&item, sizeof(Baggage));
            passenger_weight += item.weight;
        }
        
        avg_weights.push_back(passenger_weight / items);
        total_weight += passenger_weight;
        total_items += items;
        passenger_num++;
    }
    in.close();
    
    double overall_avg = total_weight / total_items;
    double m = 1.5;
    
    std::cout << "\nСтатистика:" << std::endl;
    std::cout << "Общий вес всего багажа: " << total_weight << " кг" << std::endl;
    std::cout << "Всего единиц багажа: " << total_items << std::endl;
    std::cout << "Средний вес одной вещи: " << overall_avg << " кг" << std::endl;
    std::cout << "Допустимое отклонение: +-" << m << " кг" << std::endl;
    std::cout << "\nПодходящий багаж (пассажиры): ";
    
    bool found = false;
    for (int i = 0; i < avg_weights.size(); i++) {
        if (std::abs(avg_weights[i] - overall_avg) <= m) {
            std::cout << i + 1 << " ";
            found = true;
        }
    }
    
    if (!found) std::cout << "нет";
    std::cout << std::endl;

    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
}

// Задание 4
void FileTasks::zadanie4() {
    std::cout << "\n=== ЗАДАНИЕ 4 ===" << std::endl;
    
    // Текстовый файл с 8 числами
    std::ofstream out("task4.txt");
    for (int i = 0; i < 8; i++) {
        out << (1 + rand() % 100) << std::endl;
    }
    out.close();
    
    std::ifstream in("task4.txt");
    int nums[8];
    int count = 0;
    
    while (in >> nums[count] && count < 8) {
        count++;
    }
    in.close();
    
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < 4; i++) sum1 += nums[i];
    for (int i = 4; i < 8; i++) sum2 += nums[i];
    
    std::cout << "Сумма первой половины: " << sum1 << std::endl;
    std::cout << "Сумма второй половины: " << sum2 << std::endl;
    std::cout << "Разность: " << sum1 - sum2 << std::endl;

    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
}

// Задание 5
void FileTasks::zadanie5() {
    std::cout << "\n=== ЗАДАНИЕ 5 ===" << std::endl;
    
    // Файл с числами в строках
    std::ofstream out("task5.txt");
    for (int i = 0; i < 4; i++) {
        int numbers_in_line = 2 + rand() % 3;
        for (int j = 0; j < numbers_in_line; j++) {
            out << (1 + rand() % 100) << " ";
        }
        out << std::endl;
    }
    out.close();
    
    // Суммируем
    std::ifstream in("task5.txt");
    int sum = 0;
    int num = 0;
    
    while (in >> num) {
        sum += num;
    }
    in.close();
    
    std::cout << "Сумма всех чисел: " << sum << std::endl;

    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
}

// Задание 6
void FileTasks::zadanie6() {
    std::cout << "\n=== ЗАДАНИЕ 6 ===" << std::endl;
    
    // Файл со строками
    std::ofstream out("task6.txt");
    const char* lines[] = {
        "Короткая строка",
        "Строка средней длины",
        "Очень длинная строка с большим количеством символов",
        "Еще одна",
        "Ещё длинная строка в этом файле"
    };
    
    for (int i = 0; i < 5; i++) {
        out << lines[i] << std::endl;
    }
    out.close();
    
    // Находим самую короткую и длинную
    std::ifstream in("task6.txt");
    std::string line;
    std::string shortest;
    std::string longest;
    bool first = true;
    
    while (std::getline(in, line)) {
        if (first) {
            shortest = longest = line;
            first = false;
        } else {
            if (line.length() < shortest.length()) shortest = line;
            if (line.length() > longest.length()) longest = line;
        }
    }
    in.close();
    
    std::ofstream res("task6_result.txt");
    res << "Самая короткая: " << shortest << std::endl;
    res << "Самая длинная: " << longest << std::endl;
    res.close();
    
    std::cout << "Созданы файлы: task6.txt, task6_result.txt" << std::endl;

    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
}
