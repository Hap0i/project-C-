#include <iostream>
#include <ctime>

int findFirst(int arr[], int x) {
    for (int i = 0; i < 10; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    srand(time(0));
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
    return 0;
}