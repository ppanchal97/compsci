def binary_search(arr, target):
    right = len(arr) - 1
    left = 0
    while left <= right:
        mid = (right + left) // 2
        print(left, mid, right)
        # check mid index
        if arr[mid] == target:
            return True
        elif arr[mid] < target:
            left = mid + 1
        elif arr[mid] > target:
            right = mid - 1
    return False


if __name__ == '__main__':
    arr = ['a', 'b', 'c', 'd', 'e', 'f']
    print(binary_search(arr, 'b'))
