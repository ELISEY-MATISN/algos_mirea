#include <iostream>
#include <vector>

// Функция для преобразования поддерева с корнем i в кучу
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;       // Инициализируем наибольший как корень
    int left = 2 * i + 1;  // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // Если левый дочерний больше корня
    if (left < n && arr[left] > arr[largest])
        largest = left;
    // Если правый дочерний больше, чем самый большой на данный момент
    if (right < n && arr[right] > arr[largest])
        largest = right;
    // Если самый большой не корень
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        // Рекурсивно преобразуем в кучу затронутое поддерево
        heapify(arr, n, largest);
    }
}

// Основная функция для пирамидальной сортировки
void heapSort(std::vector<int>& arr) {
    int n = arr.size();
    // Построение кучи (перегруппируем массив)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i > 0; i--) {
        // Перемещаем текущий корень в конец
        std::swap(arr[0], arr[i]);
        // Вызываем heapify на уменьшенной куче
        heapify(arr, i, 0);
    }
}

// Пример использования
int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    std::cout << "Исходный массив: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;

    heapSort(arr);

    std::cout << "Отсортированный массив: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;
    return 0;
}