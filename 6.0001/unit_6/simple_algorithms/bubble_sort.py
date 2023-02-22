import random


def bubble_sort(nums):
    is_swapped = False
    for i in range(len(nums)):
        for j in range(len(nums) - 1):
            if nums[j] > nums[j + 1]:
                # swap
                holder = nums[j]
                nums[j] = nums[j + 1]
                nums[j + 1] = holder
                is_swapped = True

        if is_swapped == False:
            return nums

    return nums


def main():
    nums = [random.randint(1, 100) for _ in range(10)]
    print(bubble_sort(nums))


main()
