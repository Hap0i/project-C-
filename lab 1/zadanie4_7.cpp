#include <iostream>
#include <ctime>

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
    return 0;
}