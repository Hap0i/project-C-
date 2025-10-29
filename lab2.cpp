#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <fstream>
#include <string>
#include <limits>
#include <locale>
#include <cstdlib>

// ������� ��� ����� ����� � ���������
int inputNumber(const std::string& prompt) {
    int value = 0;
    std::cout << prompt;
    while (!(std::cin >> value)) {
        std::cout << "������! ������� ����� �����: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return value;
}

// ������� 1
void task1() {
    std::cout << "\n=== ������� 1 ===" << std::endl;
    
    std::vector<int> V;
    std::deque<int> D;
    std::list<int> L;
    
    // ���� �������
    std::cout << "��� ������� V:" << std::endl;
    int n = 0;
    do {
        n = inputNumber("������� ���������� ��������� (������, >= 2): ");
    } while (n < 2 || n % 2 != 0);
    
    for (int i = 0; i < n; i++) {
        V.push_back(inputNumber("������� �����: "));
    }
    
    // ���� ����
    std::cout << "\n��� ���� D:" << std::endl;
    do {
        n = inputNumber("������� ���������� ��������� (������, >= 2): ");
    } while (n < 2 || n % 2 != 0);
    
    for (int i = 0; i < n; i++) {
        D.push_back(inputNumber("������� �����: "));
    }
    
    // ���� ������
    std::cout << "\n��� ������ L:" << std::endl;
    do {
        n = inputNumber("������� ���������� ��������� (������, >= 2): ");
    } while (n < 2 || n % 2 != 0);
    
    for (int i = 0; i < n; i++) {
        L.push_back(inputNumber("������� �����: "));
    }
    
    // ����� ������� ��������� � �������
    auto v1 = V.begin();
    std::advance(v1, V.size() / 2 - 1);
    auto v2 = V.begin();
    std::advance(v2, V.size() / 2);
    std::swap(*v1, *v2);
    
    // ����� ������� ��������� � ����
    auto d1 = D.begin();
    std::advance(d1, D.size() / 2 - 1);
    auto d2 = D.begin();
    std::advance(d2, D.size() / 2);
    std::swap(*d1, *d2);
    
    // ����� ������� ��������� � ������
    auto l1 = L.begin();
    std::advance(l1, L.size() / 2 - 1);
    auto l2 = L.begin();
    std::advance(l2, L.size() / 2);
    std::swap(*l1, *l2);
    
    // ����� �����������
    std::cout << "\n����������:" << std::endl;
    
    std::cout << "������ V: ";
    for (auto it = V.begin(); it != V.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << "��� D: ";
    for (auto it = D.begin(); it != D.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << "������ L: ";
    for (auto it = L.begin(); it != L.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// ������� 2
void task2() {
    std::cout << "\n=== ������� 2 ===" << std::endl;
    
    std::deque<int> D;
    
    int n = 0;
    do {
        n = inputNumber("������� ���������� ��������� ��� ���� (��������, >= 5): ");
    } while (n < 5 || n % 2 == 0);
    
    for (int i = 0; i < n; i++) {
        D.push_back(inputNumber("������� �����: "));
    }
    
    // ������� 5 ������� ���������
    int start = n / 2 - 2;
    int end = n / 2 + 3;
    
    // ��������� � ������
    D.insert(D.begin(), D.begin() + start, D.begin() + end);
    
    std::cout << "���������: ";
    for (auto it = D.begin(); it != D.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// ������� 3
void task3() {
    std::cout << "\n=== ������� 3 ===" << std::endl;
    
    std::list<int> L;
    
    int n = 0;
    do {
        n = inputNumber("������� ���������� ��������� ��� ������ (������): ");
    } while (n % 2 != 0);
    
    for (int i = 0; i < n; i++) {
        L.push_back(inputNumber("������� �����: "));
    }
    
    auto i = L.begin();
    auto r = L.end();
    r--;
    
    for (int count = 0; count < n / 2; count++) {
        L.splice(i, L, r);
        i++;
        r--;
    }
    
    std::cout << "���������: ";
    for (auto it = L.begin(); it != L.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// ������� 4
void task4() {
    std::cout << "\n=== ������� 4 ===" << std::endl;
    
    std::string filename;
    std::cout << "������� ��� �����: ";
    std::cin >> filename;
    
    std::ifstream file(filename);
    if (!file) {
        std::cout << "������ �������� �����!" << std::endl;
        return;
    }
    
    std::cout << "����� � ��������� ��������: ";
    
    int counter = 0;
    int number = 0;
    while (file >> number) {
        counter++;
        if (counter % 2 == 1) {
            std::cout << number << " ";
        }
    }
    
    std::cout << std::endl;
    file.close();
}

// ������� 5
void task5() {
    std::cout << "\n=== ������� 5 ===" << std::endl;
    
    std::vector<int> V;
    int n = inputNumber("������� ���������� ��������� ��� �������: ");
    
    for (int i = 0; i < n; i++) {
        V.push_back(inputNumber("������� �����: "));
    }
    
    // ���� ������� ��������
    int zeroCount = 0;
    int secondZeroIndex = -1;
    
    for (int i = 0; i < V.size(); i++) {
        if (V[i] == 0) {
            zeroCount++;
            if (zeroCount == 2) {
                secondZeroIndex = i;
                break;
            }
        }
    }
    
    if (secondZeroIndex != -1) {
        V.erase(V.begin() + secondZeroIndex);
        std::cout << "������ ������� ������� ������" << std::endl;
    } else {
        std::cout << "������ ������� ������� �� ������" << std::endl;
    }
    
    std::cout << "���������: ";
    for (int num : V) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// ������� 6
void task6() {
    std::cout << "\n=== ������� 6 ===" << std::endl;
    
    std::vector<int> V;
    
    int n = 0;
    do {
        n = inputNumber("������� ���������� ��������� ��� ������� (������): ");
    } while (n % 2 != 0);
    
    for (int i = 0; i < n; i++) {
        V.push_back(inputNumber("������� �����: "));
    }
    
    // ������ �������� - �������� ������������� �� -1
    for (int i = 0; i < n / 2; i++) {
        if (V[i] < 0) {
            V[i] = -1;
        }
    }
    
    // ������ �������� - �������� ������������� �� 1
    for (int i = n / 2; i < n; i++) {
        if (V[i] > 0) {
            V[i] = 1;
        }
    }
    
    std::cout << "���������: ";
    for (int num : V) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// ������� 7
void task7() {
    std::cout << "\n=== ������� 7 ===" << std::endl;
    
    std::list<int> L;
    int n = inputNumber("������� ���������� ��������� ��� ������: ");
    
    for (int i = 0; i < n; i++) {
        L.push_back(inputNumber("������� �����: "));
    }
    
    // ������� ��� ������ ��� ������ ����� �����
    std::list<int> negative, zero, positive;
    
    for (int num : L) {
        if (num < 0) {
            negative.push_back(num);
        } else if (num == 0) {
            zero.push_back(num);
        } else {
            positive.push_back(num);
        }
    }
    
    // ���������� ������
    L.clear();
    L.splice(L.end(), negative);
    L.splice(L.end(), zero);
    L.splice(L.end(), positive);
    
    std::cout << "���������: ";
    for (int num : L) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// ������� 8
void task8() {
    std::cout << "\n=== ������� 8 ===" << std::endl;
    
    std::list<int> L;
    int n = inputNumber("������� ���������� ��������� ��� ������: ");
    
    for (int i = 0; i < n; i++) {
        L.push_back(inputNumber("������� �����: "));
    }
    
    std::vector<double> V;
    
    // ��������� ������� �������������� �������� ���������
    auto it1 = L.begin();
    auto it2 = L.begin();
    it2++;
    
    while (it2 != L.end()) {
        double average = (*it1 + *it2) / 2.0;
        V.push_back(average);
        it1++;
        it2++;
    }
    
    std::cout << "������� ��������������: ";
    for (double num : V) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// ������� �������
int main() {
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
    
    std::cout << "������������ ������ �� STL" << std::endl;
    std::cout << "==========================" << std::endl;
    
    while (true) {
        std::cout << "\n�������� ������� (1-8) ��� 0 ��� ������: ";
        int choice = 0;
        std::cin >> choice;
        
        if (choice == 0) {
            break;
        }
        
        switch (choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            case 5: task5(); break;
            case 6: task6(); break;
            case 7: task7(); break;
            case 8: task8(); break;
            default: std::cout << "�������� �����!" << std::endl;
        }
    }
    
    std::cout << "��������� ���������." << std::endl;
    return 0;
}