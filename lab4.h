#pragma once
#include <iostream>

class Time {
public:
    // Конструкторы
    Time();
    Time(unsigned char h, unsigned char m);
    Time(const Time& other);

    // Метод из задания 1
    Time addMinutes(unsigned int min) const;

    // Перегрузка вывода
    friend std::ostream& operator<<(std::ostream& os, const Time& t);

    // Унарные операции (задание 2)
    Time& operator++();
    Time operator++(int);
    Time& operator--();
    Time operator--(int);

    // Приведение типа (задание 2)
    explicit operator short() const;
    operator bool() const;

    // Бинарные операции (задание 2)
    friend Time operator+(const Time& t, unsigned int min);
    friend Time operator-(const Time& t, unsigned int min);

private:
    unsigned char hours;
    unsigned char minutes;

    void normalize();
};

// Объявление функции ввода
Time inputTime();