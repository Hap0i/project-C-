#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <locale>
#include <cstdlib>

// 1 Точка координат
class Point {
public:
    Point() : x(0), y(0) {}
    Point(double x, double y) : x(x), y(y) {}
    
    double getX() const { return x; }
    double getY() const { return y; }
    
    void setX(double newX) { x = newX; }
    void setY(double newY) { y = newY; }
    
    std::string toString() const {
        return "{" + std::to_string((int)x) + ";" + std::to_string((int)y) + "}";
    }
    
    void print() const {
        std::cout << toString() << std::endl;
    }

private:
    double x;
    double y;
};

// 2 Прямая
class Line {
public:
    Line(Point start, Point end) : start(start), end(end) {}
    Line(double x1, double y1, double x2, double y2) : start(x1, y1), end(x2, y2) {}
    
    Point getStart() const { return start; }
    Point getEnd() const { return end; }
    
    void setStart(Point newStart) { start = newStart; }
    void setEnd(Point newEnd) { end = newEnd; }
    
    std::string toString() const {
        return "Линия от " + start.toString() + " до " + end.toString();
    }
    
    void print() const {
        std::cout << toString() << std::endl;
    }

private:
    Point start;
    Point end;
};

// 3 Студент
class Student {
public:
    Student(std::string name) : name(name) {}
    
    void addGrade(int grade) { grades.push_back(grade); }
    
    void setGrade(int index, int grade) {
        if (index >= 0 && index < grades.size()) {
            grades[index] = grade;
        }
    }
    
    std::vector<int> getGrades() const { return grades; }
    void setGrades(const std::vector<int>& newGrades) { grades = newGrades; }
    
    std::string toString() const {
        std::string result = name + ": [";
        for (size_t i = 0; i < grades.size(); i++) {
            result += std::to_string(grades[i]);
            if (i < grades.size() - 1) result += ", ";
        }
        result += "]";
        return result;
    }
    
    void print() const {
        std::cout << toString() << std::endl;
    }

private:
    std::string name;
    std::vector<int> grades;
};

// 4.1 Точка (обновленная)
class Point41 {
public:
    // Конструктор с параметрами
    Point41(double x, double y) : x(x), y(y) {}
    
    double getX() const { return x; }
    double getY() const { return y; }
    
    std::string toString() const {
        return "{" + std::to_string((int)x) + ";" + std::to_string((int)y) + "}";
    }
    
    void print() const {
        std::cout << toString() << std::endl;
    }

private:
    double x;
    double y;
};

// 4.2 Линия (обновленная)
class Line42 {
public:
    Line42(Point41 start, Point41 end) : start(start), end(end) {}
    Line42(double x1, double y1, double x2, double y2) : start(x1, y1), end(x2, y2) {}
    
    Point41 getStart() const { return start; }
    Point41 getEnd() const { return end; }
    
    std::string toString() const {
        return "Линия от " + start.toString() + " до " + end.toString();
    }
    
    void print() const {
        std::cout << toString() << std::endl;
    }

private:
    Point41 start;
    Point41 end;
};

// 5 Линия с длиной
class LineWithLength {
public:
    LineWithLength(double x1, double y1, double x2, double y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
    
    double getLength() const {
        double dx = x2 - x1;
        double dy = y2 - y1;
        return std::sqrt(dx * dx + dy * dy);
    }
    
    void print() const {
        std::cout << "Линия от {" << (int)x1 << ";" << (int)y1 << "} до {" 
                  << (int)x2 << ";" << (int)y2 << "} | Длина: " << getLength() << std::endl;
    }

private:
    double x1, y1, x2, y2;
};

// Функции для демонстрации заданий
void task1() {
    std::cout << "=== ЗАДАНИЕ 1: Точка координат ===" << std::endl;
    
    Point p1(1, 3);
    Point p2(5, 7);
    Point p3(2, 9);
    
    std::cout << "Точка 1: "; p1.print();
    std::cout << "Точка 2: "; p2.print();
    std::cout << "Точка 3: "; p3.print();
}

void task2() {
    std::cout << "\n=== ЗАДАНИЕ 2: Прямая ===" << std::endl;
    
    // 1. Линия 1 
    Line line1(Point(1, 3), Point(23, 8));
    std::cout << "1. "; line1.print();
    
    // 2. Линия 2
    Line line2(Point(5, 10), Point(25, 10));
    std::cout << "2. "; line2.print();
    
    // 3. Линия 3
    Line line3(line1.getStart(), line2.getEnd());
    std::cout << "3. "; line3.print();
    
    // 4. Изменение координат первой и второй линий
    std::cout << "\n4. После изменения координат первой и второй линий:" << std::endl;
    line1.setStart(Point(2, 4));
    line1.setEnd(Point(24, 9));
    line2.setStart(Point(6, 11));
    line2.setEnd(Point(26, 11));
    
    // Обновление линии 3
    line3.setStart(line1.getStart());
    line3.setEnd(line2.getEnd());
    
    std::cout << "   Линия 1: "; line1.print();
    std::cout << "   Линия 2: "; line2.print();
    std::cout << "   Линия 3: "; line3.print();
    
    // 5. Изменение координат первой линии без изменений на 3 линию 
    std::cout << "\n5. Изменение линии 1 без влияния на линию 3:" << std::endl;
    
    // Сохраняем текущие координаты начала линии 1
    Point originalStart = line1.getStart();
    
    // Меняем начало линии 1
    line1.setStart(Point(3, 5));
    line1.setEnd(Point(13, 8));
    
    // Линия 3 остается с прежними координатами
    std::cout << "   Линия 1: "; line1.print();
    std::cout << "   Линия 3: "; line3.print();
}

void task3() {
    std::cout << "\n=== ЗАДАНИЕ 3: Студент ===" << std::endl;
    
    Student vasya("Вася");
    vasya.addGrade(3);
    vasya.addGrade(4);
    vasya.addGrade(5);
    
    Student petya("Петя");
    petya.setGrades(vasya.getGrades());
    std::cout << ""; vasya.print();
    std::cout << ""; petya.print();
    petya.setGrade(0, 5);
    
    std::cout << ""; petya.print();
}

void task4() {
    std::cout << "\n=== ЗАДАНИЕ 4: Обновленные точки и линии ===" << std::endl;
    
    // Задание 4.1
    std::cout << "4.1:" << std::endl;
    Point41 p1(3, 5);
    Point41 p2(25, 6);
    Point41 p3(7, 8);
    
    std::cout << "Точка 1: "; p1.print();
    std::cout << "Точка 2: "; p2.print();
    std::cout << "Точка 3: "; p3.print();
    
    // Задание 4.2
    std::cout << "\n4.2:" << std::endl;
    Line42 line1(Point41(1, 3), Point41(23, 8));
    Line42 line2(5, 10, 25, 10);
    Line42 line3(line1.getStart(), line2.getEnd());
    
    std::cout << "Линия 1: "; line1.print();
    std::cout << "Линия 2: "; line2.print();
    std::cout << "Линия 3: "; line3.print();
}

void task5() {
    std::cout << "\n=== ЗАДАНИЕ 5: Длина линии ===" << std::endl;
    
    LineWithLength line(1, 1, 10, 15);
    line.print();
}

void showMenu() {
    std::cout << "\n========== МЕНЮ ==========" << std::endl;
    std::cout << "1. Задание 1 - Точка координат" << std::endl;
    std::cout << "2. Задание 2 - Прямая" << std::endl;
    std::cout << "3. Задание 3 - Студент" << std::endl;
    std::cout << "4. Задание 4 - Обновленные точки и линии" << std::endl;
    std::cout << "5. Задание 5 - Длина линии" << std::endl;
    std::cout << "0. Выход" << std::endl;
    std::cout << "==========================" << std::endl;
    std::cout << "Выберите задание: ";
}

int main() {
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
    int choice = 0;
    do {
        showMenu();
        std::cin >> choice;
        switch(choice) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            case 4:
                task4();
                break;
            case 5:
                task5();
                break;
            case 0:
                std::cout << "Выход из программы." << std::endl;
                break;
            default:
                std::cout << "Неверный выбор! Попробуйте снова." << std::endl;
        }
    } while (choice != 0);
    return 0;
}
