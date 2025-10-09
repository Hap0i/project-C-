#include <iostream>
#include <cmath>
#include <string>
#include <ctime>

// 1_1
double fraction(double x) {
    return x - std::floor(x);
}

// 1_3
int charToNum(char x) {
    return x - '0';
}

// 1_5
bool is2Digits(int x) {
    return (x >= 10 && x <= 99) || (x <= -10 && x >= -99);
}

// 1_7
bool isInRange(int a, int b, int num) {
    int min;
    if (a < b) {
        min = a;
    } 
    else {
        min = b;
    }
    int max;
    if (a > b) {
        max = a;
    } 
    else {
        max = b;
    }
    return num >= min && num <= max;
}

// 1_9
bool isEqual(int a, int b, int c) {
    return (a == b == c);
}

// 2_1
int abs (int x) {
    if (x < 0) {
        return -x;
    }
    else {
        return x;
    }
}

// 2_3
bool is35(int x) {
    bool del3 = (x % 3 == 0);
    bool del5 = (x % 5 == 0);
    return (del3 || del5) && !(del3 && del5);
}

// 2_5
int max3(int x, int y, int z) {
    int max = x;
    if (y > max) {
        max = y;
    }
    if (z > max) {
        max = z;
    }
    return max;
}

// 2_7
int sum2(int x, int y) {
    int sum = x + y;
    if (sum >= 10 && sum <= 19) {
        return 20;
    }
    return sum;
}

// 2_9
std::string day (int x) {
    switch(x) {
        case 1: return "Понедельник";
        break;
        case 2: return "Вторник";
        break;
        case 3: return "Среда";
        break;
        case 4: return "Четверг";
        break;
        case 5: return "Пятница";
        break;
        case 6: return "Суббота";
        break;
        case 7: return "Воскресенье";
        break;
        default: return "это не день недели";
        break;
    }
    return 0;
}

// 3_1
std::string listNums(int x) {
    std::string result = "";
    int i = 0;
    while (i <= x) {
        result += std::to_string(i) + " ";
        i++;
    }
    return result;
}

// 3_3
std::string chet (int x) {
    std::string result = "";
    int i = 0;
    while (i <= x) {
        result += std::to_string(i) + " ";
        i+=2;
    }
    return result;
}

// 3_5
int numLen (long x) {
    if (x == 0) {
        return 0;
    }
    int i = 0;
    long n = std::abs(x);
    while (n > 0) {
        n /= 10;
        i++;
    }
    return i;
}

// 3_7
void square(int x) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            std::cout << '*';
        }
        std::cout << std::endl;
    }
}

// 3_9
void rightTriangle(int x) {
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < x - i; j++) {
            std::cout << ' ';
        }
        for (int j = 0; j < i; j++) {
            std::cout << '*';
        }
        std::cout << std::endl;
    }
}

// 4_1
int findFirst(int arr[], int x) {
    for (int i = 0; i < 10; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

// 4_3
int maxAbs(int arr[], int size) {
    if (size == 0) {
        return 0;
    }
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (std::abs(arr[i]) > std::abs(maxVal)) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// 4_7
int* reverseBack(int arr[]) {
    int size = 0;
    while (arr[size] != -1) {
        size++;
    }
    int* result;
    result = new int[size + 1];
    for (int i = 0; i < size; i++) {
        result[i] = arr[size - 1 - i];
    }
    result[size] = -1;
    return result;
}


int main() {
    srand(time(0));
    int choice;
    do {
        std::cout << "МЕНЮ" << std::endl;
        std::cout << "1. Дробная часть числа" << std::endl;
        std::cout << "2. Преобразование символ в число" << std::endl;
        std::cout << "3. Двузначное число" << std::endl;
        std::cout << "4. Диапозон" << std::endl;
        std::cout << "5. Все три числа равны" << std::endl;
        std::cout << "6. Модуль числа" << std::endl;
        std::cout << "7. Делимость на 3 и 5" << std::endl;
        std::cout << "8. Максимальное из трёх" << std::endl;
        std::cout << "9. Сумма x и y" << std::endl;
        std::cout << "10. Дни недели" << std::endl;
        std::cout << "11. Числа от 0 до x" << std::endl;
        std::cout << "12. Чётные числа от 0 до x" << std::endl;
        std::cout << "13. Количество знаков в числе x" << std::endl;
        std::cout << "14. Кваддрат" << std::endl;
        std::cout << "15. Правый треугольник" << std::endl;
        std::cout << "16. Поиск первого значения" << std::endl;
        std::cout << "17. Поиск максимального" << std::endl;
        std::cout << "18. Возвратный реверс" << std::endl;
        std::cout << "0. Выход из программы" << std::endl;
        std::cout << "Введите число из меню: ";
        std::cin >> choice;
        switch(choice) {
            case 1: {
                double number;
                std::cout << "Введите число: ";
                std::cin >> number;
                double result = fraction(number);
                std::cout << "Дробная часть числа " << number << " = " << result << std::endl;
                break;
            }
            case 2: {
                char digit;
                std::cout << "Введите символ цифры (0-9): ";
                std::cin >> digit;
                int result = charToNum(digit);
                std::cout << "Числовое значение символа '" << digit << "' = " << result << std::endl;
                break;
            }
            case 3: {
                int number;
                std::cout << "Введите число: ";
                std::cin >> number;
                bool result = is2Digits(number);
                std::cout << std::boolalpha << result << std::endl;
                break;
            }
            case 4: {
                int a = 0;
                int b = 0;
                int num = 0;
                std::cout << "Введите границу a: ";
                std::cin >> a;
                std::cout << "Введите границу b: ";
                std::cin >> b;
                std::cout << "Введите число для проверки: ";
                std::cin >> num;
                bool result = isInRange(a, b, num);
                std::cout << std::boolalpha << "Результат: " << result << std::endl;
                break;
            }
            case 5: {
                int a = 0;
                int b = 0;
                int c = 0;
                std::cout << "Ведите число a: ";
                std::cin >> a;
                std::cout << "Ведите число b: ";
                std::cin >> b;
                std::cout << "Ведите число c: ";
                std::cin >> c;
                bool result = isEqual(a, b, c);
                std::cout << std::boolalpha << "Результат: " << result << std::endl;
                break;
            }
            case 6: {
                int x;
                std::cout << "Введите число x: ";
                std::cin >> x;
                int result = abs(x);
                std::cout << "Результат: " << result << std::endl;
                break;
            }
            case 7: {
                int x;
                std::cout << "Введите число: ";
                std::cin >> x;
                bool result = is35(x);
                std::cout << std::boolalpha << "Результат: " << result << std::endl;
                break;
            }
            case 8: {
                int x = 0;
                int y = 0;
                int z = 0;
                std::cout << "Введите первое число: ";
                std::cin >> x;
                std::cout << "Введите второе число: ";
                std::cin >> y;
                std::cout << "Введите третье число: ";
                std::cin >> z;
                int result = max3(x, y, z);
                std::cout << "Максимальное число: " << result << std::endl;
                break;
            }
            case 9: {
                int x = 0;
                int y = 0;
                std::cout << "Введите первое число: ";
                std::cin >> x;
                std::cout << "Введите второе число: ";
                std::cin >> y;
                int result = sum2(x, y);
                std::cout << "Результат: " << result << std::endl;
                break;
            }
            case 10: {
                int x;
                std::cout << "Введите номер дня недели (1-7): ";
                std::cin >> x;
                std::string result = day(x);
                std::cout << "Результат: " << result << std::endl;
                break;
            }
            case 11: {
                int x;
                std::cout << "Введите число x: ";
                std::cin >> x;
                std::string result = listNums(x);
                std::cout << "Числа от 0 до " << x << ": " << result << std::endl;
                break;
            }
            case 12: {
                int x;
                std::cout << "Введите число x: ";
                std::cin >> x;
                std::string result = chet(x);
                std::cout << "Числа от 0 до " << x << ": " << result << std::endl;
                break;
            }
            case 13: {
                long x;
                std::cout << "Введите число x: ";
                std::cin >> x;
                int result = numLen(x);
                std:: cout << "Количество знаков в числе x: " << result << std::endl;
                break;
            }
            case 14: {
                int x;
                std::cout << "Введите размер квадрата: ";
                std::cin >> x;
                square(x);
                break;
            }
            case 15: {
                int x;
                std::cout << "Введите высоту треугольника: ";
                std::cin >> x;
                rightTriangle(x);
                break;
            }
            case 16: {
                int arr[10];
                std::cout << "Сгенерированный массив: ";
                for (int i = 0; i < 10; i++) {
                    arr[i] = rand() % 100;
                    std::cout << arr[i] << " ";
                }
                std::cout << std::endl;
                int x;
                std::cout << "Введите число для поиска: ";
                std::cin >> x;
                int result = findFirst(arr, x);
                if (result == -1) {
                    std::cout << "Результат: " << result << std::endl;
                } 
                else {
                    std::cout << "Результат: " << result << std::endl;
                }
                break;
            }
            case 17: {
                int size;
                std::cout << "Введите размер массива: ";
                std::cin >> size;
                int arr[size];
                std::cout << "arr= [ ";
                for (int i = 0; i < size; i++) {
                    arr[i] = rand() % 200 - 100;
                    std::cout << arr[i] << " ";
                }
                std::cout << "]";
                std::cout << std::endl;
                int result = maxAbs(arr, size);
                std::cout << "Результат: " << result << std::endl;
                break;
            }
            case 18: {
                int size;
                std::cout << "Введите размер массива: ";
                std::cin >> size;
                int arr[size + 1];
                std::cout << "Исходный массив: ";
                for (int i = 0; i < size; i++) {
                    arr[i] = rand() % 200 - 100;
                    std::cout << arr[i] << " ";
                }
                arr[size] = -1;
                std::cout << std::endl;
                int* reversed = reverseBack(arr);
                std::cout << "Перевернутый массив: ";
                for (int i = 0; reversed[i] != -1; i++) {
                    std::cout << reversed[i] << " ";
                }
                std::cout << std::endl;
                break;
            }
            case 0:
                std::cout << "Выход из программы" << std::endl;
                break;
            default:
                std::cout << "Неверный выбор, введите число из меню(1-18)" << std::endl;
        }
    }
    while(choice != 0);
    return 0;
}