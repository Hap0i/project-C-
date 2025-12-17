#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>
#include <cstring>
#include <locale>
#include <cstdlib>
#include <cmath>
#include "lab5.h"

// === МЕТОДЫ ЗАПОЛНЕНИЯ ФАЙЛОВ ===

void FileTasks::fillBinaryWithNumbers(const std::string& filename, int count) {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "ОШИБКА: Не удалось создать файл " << filename << std::endl;
        return;
    }
    
    std::cout << "Создаю файл " << filename << " с " << count << " числами" << std::endl;
    
    for (int i = 0; i < count; i++) {
        int num = 1 + rand() % 100;
        file.write((char*)&num, sizeof(num));
    }
    file.close();
    
    if (file.fail()) {
        std::cerr << "ОШИБКА: Проблема при записи в файл " << filename << std::endl;
    }
}

void FileTasks::fillBinaryWithBaggage(const std::string& filename, int passengers) {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "ОШИБКА: Не удалось создать файл " << filename << std::endl;
        return;
    }
    
    std::cout << "Создаю файл " << filename << " с багажом " << passengers << " пассажиров" << std::endl;
    
    for (int p = 0; p < passengers; p++) {
        int items = 2 + rand() % 3; // 2-4 вещи
        file.write((char*)&items, sizeof(int));
        
        for (int i = 0; i < items; i++) {
            Baggage item;
            const char* names[] = {"Чемодан", "Сумка", "Рюкзак", "Коробка"};
            strcpy(item.name, names[rand() % 4]);
            item.weight = 1.0 + (rand() % 300) / 10.0;
            file.write((char*)&item, sizeof(Baggage));
        }
    }
    file.close();
    
    if (file.fail()) {
        std::cerr << "ОШИБКА: Проблема при записи в файл " << filename << std::endl;
    }
}

void FileTasks::fillTextOnePerLine(const std::string& filename, int count) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "ОШИБКА: Не удалось создать файл " << filename << std::endl;
        return;
    }
    
    std::cout << "Создаю текстовый файл " << filename << " с " << count << " числами" << std::endl;
    
    for (int i = 0; i < count; i++) {
        file << (1 + rand() % 100) << std::endl;
    }
    file.close();
    
    if (file.fail()) {
        std::cerr << "ОШИБКА: Проблема при записи в файл " << filename << std::endl;
    }
}

void FileTasks::fillTextMultiplePerLine(const std::string& filename, int lines, int maxPerLine) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "ОШИБКА: Не удалось создать файл " << filename << std::endl;
        return;
    }
    
    std::cout << "Создаю текстовый файл " << filename << " с " << lines << " строками" << std::endl;
    
    for (int i = 0; i < lines; i++) {
        int numbers_in_line = 2 + rand() % (maxPerLine - 1);
        for (int j = 0; j < numbers_in_line; j++) {
            file << (1 + rand() % 100) << " ";
        }
        file << std::endl;
    }
    file.close();
    
    if (file.fail()) {
        std::cerr << "ОШИБКА: Проблема при записи в файл " << filename << std::endl;
    }
}

void FileTasks::fillTextWithLines(const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "ОШИБКА: Не удалось создать файл " << filename << std::endl;
        return;
    }
    
    std::cout << "Создаю текстовый файл " << filename << " со строками" << std::endl;
    
    const char* lines[] = {
        "Короткая строка",
        "Строка средней длины",
        "Очень длинная строка с большим количеством символов",
        "Еще одна",
        "Ещё длинная строка в этом файле"
    };
    
    for (int i = 0; i < 5; i++) {
        file << lines[i] << std::endl;
    }
    file.close();
    
    if (file.fail()) {
        std::cerr << "ОШИБКА: Проблема при записи в файл " << filename << std::endl;
    }
}

// === МЕТОДЫ ВЫПОЛНЕНИЯ ЗАДАНИЙ ===

void FileTasks::zadanie1() {
    std::cout << "\n=== ЗАДАНИЕ 1 ===" << std::endl;
    std::cout << "Четные числа из бинарного файла\n" << std::endl;
    
    fillBinaryWithNumbers("task1(1).bin", 10);
    
    // Проверяем файл
    std::ifstream read_file("task1(1).bin", std::ios::binary);
    if (!read_file) {
        std::cerr << "ОШИБКА: Не удалось открыть файл task1(1).bin для чтения" << std::endl;
        return;
    }
    
    std::ofstream even_file("task1(2).bin", std::ios::binary);
    if (!even_file) {
        std::cerr << "ОШИБКА: Не удалось создать файл task1(2).bin" << std::endl;
        read_file.close();
        return;
    }
    
    std::vector<int> even_numbers;
    int num = 0;
    
    std::cout << "Исходные числа из файла task1(1).bin: ";
    while (read_file.read((char*)&num, sizeof(num))) {
        std::cout << num << " ";
        if (num % 2 == 0) {
            even_numbers.push_back(num);
            even_file.write((char*)&num, sizeof(num));
        }
    }
    
    if (read_file.bad()) {
        std::cerr << "\nОШИБКА: Проблема при чтении файла task1(1).bin" << std::endl;
    }
    
    read_file.close();
    even_file.close();
    
    std::cout << std::endl << "Четные числа (записаны в task1(2).bin): ";
    for (int n : even_numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Найдено четных чисел: " << even_numbers.size() << std::endl;
}

void FileTasks::zadanie2() {
    std::cout << "\n=== ЗАДАНИЕ 2 ===" << std::endl;
    std::cout << "Матрица из бинарного файла\n" << std::endl;
    
    fillBinaryWithNumbers("task2.bin", 8);
    
    // Проверяем файл
    std::ifstream in("task2.bin", std::ios::binary);
    if (!in) {
        std::cerr << "ОШИБКА: Не удалось открыть файл task2.bin" << std::endl;
        return;
    }
    
    int nums[8];
    int count = 0;
    
    while (in.read((char*)&nums[count], sizeof(int)) && count < 8) {
        count++;
    }
    
    if (in.bad()) {
        std::cerr << "ОШИБКА: Проблема при чтении файла task2.bin" << std::endl;
        in.close();
        return;
    }
    in.close();
    
    if (count == 0) {
        std::cerr << "ОШИБКА: Файл task2.bin пуст или содержит некорректные данные" << std::endl;
        return;
    }
    
    // Матрица 3x3
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
    
    std::cout << "Матрица 3x3 из файла task2.bin:" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    
    // Меняем min и max
    for (int i = 0; i < 3; i++) {
        int min_idx = 0;
        int max_idx = 0;
        for (int j = 1; j < 3; j++) {
            if (matrix[i][j] < matrix[i][min_idx]) min_idx = j;
            if (matrix[i][j] > matrix[i][max_idx]) max_idx = j;
        }
        int temp = matrix[i][min_idx];
        matrix[i][min_idx] = matrix[i][max_idx];
        matrix[i][max_idx] = temp;
    }
    
    std::cout << "\nПосле замены min и max в каждой строке:" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void FileTasks::zadanie3() {
    std::cout << "\n=== ЗАДАНИЕ 3 ===" << std::endl;
    std::cout << "Багаж пассажиров\n" << std::endl;
    
    fillBinaryWithBaggage("task3.bin", 3);
    
    // Проверка данных
    std::ifstream in("task3.bin", std::ios::binary);
    if (!in) {
        std::cerr << "ОШИБКА: Не удалось открыть файл task3.bin" << std::endl;
        return;
    }
    
    double total_weight = 0;
    int total_items = 0;
    std::vector<double> avg_weights;
    int passenger_num = 0;
    
    std::cout << "Данные о багаже из файла task3.bin:" << std::endl;
    
    while (!in.eof()) {
        int items = 0;
        if (!in.read((char*)&items, sizeof(int))) {
            if (in.eof()) break;
            std::cerr << "ОШИБКА: Не удалось прочитать количество вещей" << std::endl;
            break;
        }
        
        if (items <= 0 || items > 100) {
            std::cerr << "ОШИБКА: Некорректное количество вещей: " << items << std::endl;
            break;
        }
        
        std::cout << "\nПассажир " << (passenger_num + 1) << " (" << items << " вещей):" << std::endl;
        
        double passenger_weight = 0;
        bool error = false;
        for (int i = 0; i < items; i++) {
            Baggage item;
            if (!in.read((char*)&item, sizeof(Baggage))) {
                std::cerr << "ОШИБКА: Не удалось провести данные багажа" << std::endl;
                error = true;
                break;
            }
            passenger_weight += item.weight;
            std::cout << "  " << item.name << ": " << item.weight << " кг" << std::endl;
        }

        if (items > 0) {
            double avg = passenger_weight / items;
            avg_weights.push_back(avg);
            total_weight += passenger_weight;
            total_items += items;
            passenger_num++;
            
            std::cout << "  Средний вес вещи: " << avg << " кг" << std::endl;
        }
    }
    
    if (in.bad()) {
        std::cerr << "ОШИБКА: Проблема при чтении файла task3.bin" << std::endl;
    }
    in.close();
    
    if (total_items == 0) {
        std::cerr << "ОШИБКА: Нет данных для анализа" << std::endl;
        return;
    }
    
    // Выводим статистику
    double overall_avg = total_weight / total_items;
    double m = 1.5;
    
    std::cout << "\nОбщая статистика:" << std::endl;
    std::cout << "Общий вес всего багажа: " << total_weight << " кг" << std::endl;
    std::cout << "Всего единиц багажа: " << total_items << std::endl;
    std::cout << "Средний вес одной вещи: " << overall_avg << " кг" << std::endl;
    std::cout << "Допустимое отклонение: +-" << m << " кг" << std::endl;
    
    std::cout << "\nПассажиры, у которых средний вес вещи в пределах " << m << " кг от общего среднего: ";
    bool found = false;
    for (int i = 0; i < avg_weights.size(); i++) {
        if (std::abs(avg_weights[i] - overall_avg) <= m) {
            std::cout << (i + 1) << " ";
            found = true;
        }
    }
    if (!found) std::cout << "нет";
    std::cout << std::endl;
}

void FileTasks::zadanie4() {
    std::cout << "\n=== ЗАДАНИЕ 4 ===" << std::endl;
    std::cout << "Разность сумм половин файла\n" << std::endl;
    
    fillTextOnePerLine("task4.txt", 8);
    
    // Проверяем файл
    std::ifstream in("task4.txt");
    if (!in) {
        std::cerr << "ОШИБКА: Не удалось открыть файл task4.txt" << std::endl;
        return;
    }
    
    int nums[8];
    int count = 0;
    
    std::cout << "Числа из файла task4.txt: ";
    while (in >> nums[count] && count < 8) {
        std::cout << nums[count] << " ";
        count++;
    }
    
    if (in.bad()) {
        std::cerr << "\nОШИБКА: Проблема при чтении файла task4.txt" << std::endl;
        in.close();
        return;
    }
    in.close();
    
    if (count < 8) {
        std::cout << "\nПРЕДУПРЕЖДЕНИЕ: В файле только " << count << " чисел вместо 8" << std::endl;
    }
    
    std::cout << std::endl;
    
    int sum1 = 0;
    int sum2 = 0;
    int half = count / 2;
    
    for (int i = 0; i < half; i++) sum1 += nums[i];
    for (int i = half; i < count; i++) sum2 += nums[i];
    
    std::cout << "Сумма первых " << half << " чисел: " << sum1 << std::endl;
    std::cout << "Сумма последних " << (count - half) << " чисел: " << sum2 << std::endl;
    std::cout << "Разность (первые - последние): " << sum1 - sum2 << std::endl;
}

void FileTasks::zadanie5() {
    std::cout << "\n=== ЗАДАНИЕ 5 ===" << std::endl;
    std::cout << "Сумма всех чисел в файле\n" << std::endl;
    
    fillTextMultiplePerLine("task5.txt", 4, 5);
    
    // Проверяем файл
    std::ifstream in("task5.txt");
    if (!in) {
        std::cerr << "ОШИБКА: Не удалось открыть файл task5.txt" << std::endl;
        return;
    }
    
    int sum = 0;
    int num = 0;
    int numbers_count = 0;
    
    std::cout << "Содержимое файла task5.txt:" << std::endl;
    std::string line;
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        
        std::cout << line << std::endl;
        
        // Считываем числа из строки
        std::istringstream iss(line);
        while (iss >> num) {
            sum += num;
            numbers_count++;
        }
        
        if (iss.fail() && !iss.eof()) {
            std::cerr << "ПРЕДУПРЕЖДЕНИЕ: Некорректные данные в строке" << std::endl;
        }
    }
    
    if (in.bad()) {
        std::cerr << "ОШИБКА: Проблема при чтении файла task5.txt" << std::endl;
    }
    in.close();
    
    if (numbers_count == 0) {
        std::cout << "Файл не содержит чисел" << std::endl;
    } else {
        std::cout << "\nНайдено чисел: " << numbers_count << std::endl;
        std::cout << "Сумма всех чисел в файле: " << sum << std::endl;
    }
}

void FileTasks::zadanie6() {
    std::cout << "\n=== ЗАДАНИЕ 6 ===" << std::endl;
    std::cout << "Самая короткая и длинная строка\n" << std::endl;
    
    fillTextWithLines("task6.txt");
    
    // Проверяем файл
    std::ifstream in("task6.txt");
    if (!in) {
        std::cerr << "ОШИБКА: Не удалось открыть файл task6.txt" << std::endl;
        return;
    }
    
    std::string line;
    std::string shortest;
    std::string longest;
    bool first = true;
    int line_count = 0;
    
    std::cout << "Содержимое файла task6.txt:" << std::endl;
    while (std::getline(in, line)) {
        line_count++;
        std::cout << line_count << ". \"" << line << "\" (длина: " << line.length() << ")" << std::endl;
        
        if (first) {
            shortest = longest = line;
            first = false;
        } else {
            if (line.length() < shortest.length()) shortest = line;
            if (line.length() > longest.length()) longest = line;
        }
    }
    
    if (in.bad()) {
        std::cerr << "ОШИБКА: Проблема при чтении файла task6.txt" << std::endl;
    }
    in.close();
    
    if (line_count == 0) {
        std::cerr << "ОШИБКА: Файл task6.txt пуст" << std::endl;
        return;
    }
    
    std::ofstream res("task6_result.txt");
    if (!res) {
        std::cerr << "ОШИБКА: Не удалось создать файл task6_result.txt" << std::endl;
        return;
    }
    
    res << "Самая короткая строка (" << shortest.length() << " символов): " << shortest << std::endl;
    res << "Самая длинная строка (" << longest.length() << " символов): " << longest << std::endl;
    res.close();
    
    if (res.fail()) {
        std::cerr << "ОШИБКА: Проблема при записи в файл task6_result.txt" << std::endl;
    }
    
    std::cout << "\nРезультат записан в task6_result.txt:" << std::endl;
    std::cout << "Самая короткая: \"" << shortest << "\" (" << shortest.length() << " символов)" << std::endl;
    std::cout << "Самая длинная: \"" << longest << "\" (" << longest.length() << " символов)" << std::endl;
}
