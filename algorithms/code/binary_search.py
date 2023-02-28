def binary_search(list, element, low, high):
    if low > high:
        return False
    else:
        middle = (low + high) // 2
        if list[middle] == element:
            return True
        elif list[middle] < element:
            return binary_search(list, element, middle + 1, high)
        else:
            return binary_search(list, element, low, middle - 1)


def main():
    nums = [213, 245, 21, 678, 123, 3, 2, 0, 1]
    # Demonstrate Amortized Cost for Sorting List
    nums.sort()
    print(binary_search(nums, 213, 0, len(nums) - 1))


main()
