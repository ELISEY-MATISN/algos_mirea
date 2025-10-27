def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i  # Возвращаем индекс, если нашли
    return -1  # Возвращаем -1, если не нашли

# Пример использования
if __name__ == "__main__":
    array = [3, 5, 2, 7, 9, 1, 4]
    target = 7
    result = linear_search(array, target)
    if result != -1:
        print(f"Элемент найден на позиции: {result}")
    else:
        print("Элемент не найден")