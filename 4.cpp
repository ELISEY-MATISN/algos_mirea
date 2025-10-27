#include <iostream>
#include <vector>

// Функция для слияния двух отсортированных подмассивов
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Создаем временные подмассивы
    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Сливаем временные массивы обратно в arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // Копируем оставшиеся элементы L[], если есть
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    // Копируем оставшиеся элементы R[], если есть
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Основная функция сортировки слиянием
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) return; // Базовый случай рекурсии

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);     // Сортируем первую половину
    mergeSort(arr, mid + 1, right); // Сортируем вторую половину
    merge(arr, left, mid, right);  // Сливаем отсортированные половины
}

// Пример использования
int main() {
    std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    std::cout << "Исходный массив: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;

    mergeSort(arr, 0, arr.size() - 1);

    std::cout << "Отсортированный массив: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;
    return 0;
}