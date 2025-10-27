def quick_sort(arr, low, high):
    if low < high:
        # pi - индекс опорного элемента, arr[pi] на своем месте
        pi = partition(arr, low, high)
        # Рекурсивно сортируем элементы до и после разбиения
        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)

def partition(arr, low, high):
    # Выбираем последний элемент作为опорный
    pivot = arr[high]
    i = low - 1  # Индекс меньшего элемента
    for j in range(low, high):
        # Если текущий элемент меньше или равен опорному
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    # Помещаем опорный элемент после всех меньших элементов
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

# Пример использования
if __name__ == "__main__":
    array = [10, 7, 8, 9, 1, 5]
    print("Исходный массив:", array)
    quick_sort(array, 0, len(array) - 1)
    print("Отсортированный массив:", array)