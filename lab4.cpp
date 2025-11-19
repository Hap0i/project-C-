#include <iostream>
#include <limits>
#include <locale>
#include <cstdlib>

class Time {
private:
    unsigned char hours;
    unsigned char minutes;

    void normalize() {
        hours = (hours + (minutes / 60)) % 24;
        minutes %= 60;
    }

public:
    // Конструкторы
    Time() : hours(0), minutes(0) {}
    Time(unsigned char h, unsigned char m) : hours(h), minutes(m) { normalize(); }
    Time(const Time& other) : hours(other.hours), minutes(other.minutes) {}

    // Метод из задания 1
    Time addMinutes(unsigned int min) const {
        Time result = *this;
        result.minutes += min;
        result.normalize();
        return result;
    }

    // Перегрузка вывода
    friend std::ostream& operator<<(std::ostream& os, const Time& t) {
        if (t.hours < 10) os << "0";
        os << (int)t.hours << ":";
        if (t.minutes < 10) os << "0";
        os << (int)t.minutes;
        return os;
    }

    // Унарные операции (задание 2)
    Time& operator++() {
        ++minutes;
        normalize();
        return *this;
    }

    Time operator++(int) {
        Time temp = *this;
        ++(*this);
        return temp;
    }

    Time& operator--() {
        if (minutes == 0) {
            minutes = 59;
            hours = (hours == 0) ? 23 : hours - 1;
        } else {
            --minutes;
        }
        return *this;
    }

    Time operator--(int) {
        Time temp = *this;
        --(*this);
        return temp;
    }

    // Приведение типа (задание 2)
    explicit operator short() const { return hours; }
    operator bool() const { return hours != 0 || minutes != 0; }

    // Бинарные операции (задание 2)
    friend Time operator+(const Time& t, unsigned int min) {
        return t.addMinutes(min);
    }

    friend Time operator-(const Time& t, unsigned int min) {
        int total = t.hours * 60 + t.minutes - min;
        while (total < 0) total += 1440;
        return Time(total / 60, total % 60);
    }
};

Time inputTime() {
    int h = 0;
    int m = 0;
    std::cout << "Часы (0-23): ";
    std::cin >> h;
    std::cout << "Минуты (0-59): ";
    std::cin >> m;
    return Time(h, m);
}

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
    std::cout << "--t: " << --t1 << "\n";
    std::cout << "t--: " << t1-- << " (после: " << t1 << ")\n\n";

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