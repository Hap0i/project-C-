#include <iostream>
#include <cstdlib>
#include <ctime>

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

int main() {
    srand(time(0));
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
    return 0;
}