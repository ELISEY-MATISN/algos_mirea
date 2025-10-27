def insertion_sort(arr):
    # Проходим по всем элементам, начиная со второго
    for i in range(1, len(arr)):
        key = arr[i]  # Текущий элемент, который нужно вставить
        j = i - 1     # Индекс предыдущего элемента
        # Сдвигаем элементы arr[0..i-1], которые больше key, на одну позицию вперед
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        # Вставляем key на найденное место
        arr[j + 1] = key

# Пример использования
if __name__ == "__main__":
    array = [12, 11, 13, 5, 6]
    print("Исходный массив:", array)
    insertion_sort(array)
    print("Отсортированный массив:", array)