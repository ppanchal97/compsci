import random


def merge(l1, l2):
    result = []
    i = 0
    j = 0

    while i < len(l1) and j < len(l2):
        if l1[i] < l2[j]:
            result.append(l1[i])
            i += 1
        else:
            result.append(l2[j])
            j += 1

    # append remaining lists
    # for loop implementation
    for k in range(i, len(l1)):
        result.append(l1[k])

    # while loop implementation
    while (j < len(l2)):
        result.append(l2[j])
        j += 1

    return result


def merge_sort(nums):
    if len(nums) < 2:
        return nums
    else:
        middle = len(nums) // 2
        left = merge_sort(nums[:middle])
        right = merge_sort(nums[middle:])
        return merge(left, right)


def main():
    nums = [random.randint(1, 100) for _ in range(10)]
    print(merge_sort(nums))


main()
