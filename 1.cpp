#include <iostream>
#include <vector>

void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        // Находим индекс минимального элемента в неотсортированной части
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Меняем найденный минимальный элемент с первым неотсортированным
        std::swap(arr[i], arr[minIndex]);
    }
}

// Пример использования
int main() {
    std::vector<int> arr = {64, 25, 12, 22, 11};
    std::cout << "Исходный массив: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;

    selectionSort(arr);

    std::cout << "Отсортированный массив: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;
    return 0;
}