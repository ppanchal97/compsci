import random


def selection_sort(nums):
    for i in range(len(nums)):
        minimum = nums[i]
        minimum_position = i

        for j in range(i, len(nums)):
            if nums[j] < minimum:
                minimum = nums[j]
                minimum_position = j

        nums[minimum_position] = nums[i]
        nums[i] = minimum

    return nums


def main():
    nums = [random.randint(1, 100) for _ in range(10)]
    print(selection_sort(nums))


main()
