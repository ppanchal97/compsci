# Recursive approach
def bisection_search_recursive(arr, low, high, target):
    if low > high:
        return None

    mid = (low + high) // 2

    if arr[mid] == target:
        return 0
    elif arr[mid] > target:
        return bisection_search_recursive(arr, low, mid - 1, target)
    else:
        return bisection_search_recursive(arr, mid + 1, high, target)
    

# Iterative approach
def bisection_search_iterative(arr, target):
    low = 0
    high = len(arr) - 1
    
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == target:
            return 0
        elif arr[mid] >= target:
            high = mid - 1
        else:
            low = mid + 1

    return None

def main():
    nums = [100, 200, 300, 400, 500, 600, 700]
    target = 1020
    print(bisection_search_recursive(nums, 0, len(nums) - 1, target))
    print(bisection_search_iterative(nums, target))


main()