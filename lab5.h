#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>

class FileTasks {
public:
    // 1-2
    static void fillBinaryWithNumbers(const std::string& filename, int count);
    // 3
    static void fillBinaryWithBaggage(const std::string& filename, int passengers);
    // 4
    static void fillTextOnePerLine(const std::string& filename, int count);
    // 5
    static void fillTextMultiplePerLine(const std::string& filename, int lines, int maxPerLine);
    // 6
    static void fillTextWithLines(const std::string& filename);
    
    static void zadanie1();
    static void zadanie2();
    static void zadanie3();
    static void zadanie4();
    static void zadanie5();
    static void zadanie6();
};

// Структура для задания 3
    struct Baggage {
        char name[20];
        double weight;
    };
