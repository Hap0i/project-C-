#include <iostream>
#include "lab4.h"

// Реализация методов класса Time
void Time::normalize() {
    hours = (hours + (minutes / 60)) % 24;
    minutes %= 60;
}

// Конструкторы
Time::Time() : hours(0), minutes(0) {}

Time::Time(unsigned char h, unsigned char m) : hours(h), minutes(m) { 
    normalize(); 
}

Time::Time(const Time& other) : hours(other.hours), minutes(other.minutes) {}

// Метод из задания 1
Time Time::addMinutes(unsigned int min) const {
    Time result = *this;
    result.minutes += min;
    result.normalize();
    return result;
}

// Перегрузка вывода
std::ostream& operator<<(std::ostream& os, const Time& t) {
    if (t.hours < 10) os << "0";
    os << (int)t.hours << ":";
    if (t.minutes < 10) os << "0";
    os << (int)t.minutes;
    return os;
}

// Унарные операции (задание 2)
Time& Time::operator++() {
    ++minutes;
    normalize();
    return *this;
}

Time Time::operator++(int) {
    Time temp = *this;
    ++(*this);
    return temp;
}

Time& Time::operator--() {
    if (minutes == 0) {
        minutes = 59;
        hours = (hours == 0) ? 23 : hours - 1;
    } else {
        --minutes;
    }
    return *this;
}

Time Time::operator--(int) {
    Time temp = *this;
    --(*this);
    return temp;
}

// Приведение типа (задание 2)
Time::operator short() const { 
    return hours; 
}

Time::operator bool() const { 
    return hours != 0 || minutes != 0; 
}

// Бинарные операции (задание 2)
Time operator+(const Time& t, unsigned int min) {
    return t.addMinutes(min);
}

Time operator-(const Time& t, unsigned int min) {
    int total = t.hours * 60 + t.minutes - min;
    while (total < 0) total += 1440;
    return Time(total / 60, total % 60);
}

// Реализация функции ввода
Time inputTime() {
    int h = 0;
    int m = 0;
    std::cout << "Часы (0-23): ";
    std::cin >> h;
    std::cout << "Минуты (0-59): ";
    std::cin >> m;
    return Time(h, m);
}