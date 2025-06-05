def merge_sorted(arr1: list[int], m: int, arr2: list[int], n: int) -> None:
    k = m + n - 1
    i = m - 1
    j = n - 1
    while i >= 0 and j >= 0:
        if arr1[i] > arr2[j]:
            arr1[k] = arr1[i]
            i -= 1
            k -= 1
        else:
            arr1[k] = arr2[j]
            j -= 1
            k -= 1

if __name__ == '__main__':
    arr1 = [1, 2, 3, 4, 0, 0, 0]
    arr2 = [8, 9, 10]
    merge_sorted(arr1, 4, arr2, 3)
    print(arr1)
