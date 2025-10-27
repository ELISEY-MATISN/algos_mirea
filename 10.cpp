#include <iostream>
#include <vector>

// Рекурсивная версия интерполяционного поиска
int interpolationSearch(std::vector<int>& arr, int low, int high, int target) {
    // Условие выхода: target должен быть в диапазоне [arr[low], arr[high]]
    if (low <= high && target >= arr[low] && target <= arr[high]) {
        // Формула для вычисления позиции
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]));

        if (arr[pos] == target)
            return pos;
        if (arr[pos] < target)
            return interpolationSearch(arr, pos + 1, high, target);
        if (arr[pos] > target)
            return interpolationSearch(arr, low, pos - 1, target);
    }
    return -1;
}

// Пример использования
int main() {
    std::vector<int> arr = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
    int target = 18;
    int result = interpolationSearch(arr, 0, arr.size() - 1, target);
    if (result != -1)
        std::cout << "Элемент найден на позиции: " << result << std::endl;
    else
        std::cout << "Элемент не найден" << std::endl;
    return 0;
}