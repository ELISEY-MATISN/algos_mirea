#include <iostream>
#include <vector>

// Итеративная версия бинарного поиска
int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Предотвращает переполнение

        // Проверяем, находится ли target в середине
        if (arr[mid] == target)
            return mid;
        // Если target больше, игнорируем левую половину
        else if (arr[mid] < target)
            left = mid + 1;
        // Если target меньше, игнорируем правую половину
        else
            right = mid - 1;
    }
    // Если элемент не найден
    return -1;
}

// Пример использования
int main() {
    std::vector<int> sortedArray = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 7;
    int result = binarySearch(sortedArray, target);
    if (result != -1)
        std::cout << "Элемент найден на позиции: " << result << std::endl;
    else
        std::cout << "Элемент не найден" << std::endl;
    return 0;
}