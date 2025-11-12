ОТЧЁТ по лабораторной работе по программированию на C++
Тема: "ОБЪЕКТНО-ОРИЕНТИРОВАННОЕ ПРОГРАММИРОВАНИЕ"
Цель работы
Освоение принципов объектно-ориентированного программирования на C++, включая создание классов, инкапсуляцию данных, наследование, полиморфизм и работу с конструкторами. Разработка и тестирование классов для представления различных сущностей.

Описание задач и их решения


Задача 1: Точка координат
Описание: Создать класс Point для представления точки на двумерной плоскости с координатами X и Y.

Решение:
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
Алгоритм: Класс инкапсулирует координаты точки, предоставляет конструкторы для инициализации, геттеры/сеттеры для доступа к данным и методы для текстового представления.

Тесты:
Точка 1: {1;3}
Точка 2: {5;7}
Точка 3: {2;9}


Задача 2: Прямая
Описание: Создать класс Line для представления линии на плоскости, используя класс Point.

Решение:
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
Алгоритм: Класс Line использует композицию с классом Point. Реализованы различные конструкторы и методы для работы с линией.

Тесты:
1. Линия от {1;3} до {23;8}
2. Линия от {5;10} до {25;10}
3. Линия от {1;3} до {25;10}

После изменения координат:
Линия 1: Линия от {2;4} до {24;9}
Линия 2: Линия от {6;11} до {26;11}
Линия 3: Линия от {2;4} до {26;11}

Изменение линии 1 без влияния на линию 3:
Линия 1: Линия от {3;5} до {13;8}
Линия 3: Линия от {2;4} до {26;11}


Задача 3: Студент
Описание: Создать класс Student для представления студента с именем и списком оценок.

Решение:
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
Алгоритм: Класс управляет данными студента, предоставляет методы для добавления и изменения оценок, демонстрирует работу с динамическими массивами (vector).

Тесты:
Вася: [3, 4, 5]
Петя: [3, 4, 5]
Петя: [5, 4, 5]


Задача 4.1: Точка (обновленная)
Описание: Создать класс Point41 без конструктора по умолчанию.

Решение:
class Point41 {
public:
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
Алгоритм: Класс демонстрирует обязательную инициализацию через конструктор с параметрами.

Тесты:
Точка 1: {3;5}
Точка 2: {25;6}
Точка 3: {7;8}


Задача 4.2: Линия (обновленная)
Описание: Создать класс Line42, работающий с Point41.

Решение:
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
Алгоритм: Класс демонстрирует композицию с обязательной инициализацией.

Тесты:
Линия 1: Линия от {1;3} до {23;8}
Линия 2: Линия от {5;10} до {25;10}
Линия 3: Линия от {1;3} до {25;10}


Задача 5: Линия с длиной
Описание: Создать класс LineWithLength с методом вычисления длины линии.

Решение:
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
Алгоритм: Класс вычисляет длину линии по теореме Пифагора.

Тесты:
Линия от {1;1} до {10;15} | Длина: 16.6433


Заключение
5.1. Выводы
В ходе лабораторной работы были успешно реализованы 5 основных заданий по объектно-ориентированному программированию. Созданы классы для представления различных сущностей, освоены принципы инкапсуляции, композиции и управления состоянием объектов.

5.2. Результаты
Реализованы 5 классов с полной функциональностью
Создана система меню для удобного тестирования
Все классы протестированы и работают корректно
Реализована обработка пользовательского ввода
