def shell_sort(arr):
    n = len(arr)
    # Начинаем с большого шага, затем уменьшаем его
    gap = n // 2
    while gap > 0:
        # Применяем сортировку вставками для этого шага
        for i in range(gap, n):
            temp = arr[i]
            j = i
            # Сдвигаем элементы, пока не найдем правильное место для arr[i]
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            # Вставляем temp на правильное место
            arr[j] = temp
        gap //= 2  # Уменьшаем шаг

# Пример использования
if __name__ == "__main__":
    arr = [12, 34, 54, 2, 3]
    print("Исходный массив:", arr)
    shell_sort(arr)
    print("Отсортированный массив:", arr)