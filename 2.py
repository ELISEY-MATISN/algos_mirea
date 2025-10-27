def bubble_sort(arr):
    n = len(arr)
    # Проходим по всем элементам массива
    for i in range(n):
        # Флаг для оптимизации: если не было обменов, массив отсортирован
        swapped = False
        # Последние i элементов уже на своем месте
        for j in range(0, n - i - 1):
            # Меняем элементы, если текущий больше следующего
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        # Если не было обменов, выходим из цикла
        if not swapped:
            break

# Пример использования
if __name__ == "__main__":
    test_array = [64, 34, 25, 12, 22, 11, 90]
    print("Исходный массив:", test_array)
    bubble_sort(test_array)
    print("Отсортированный массив:", test_array)