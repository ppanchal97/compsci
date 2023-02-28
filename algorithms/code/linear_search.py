def linear_search(list, element):
    for i in list:
        if i == element:
            return True

    return False


def main():
    nums = [213, 245, 21, 678, 123, 3, 2, 0, 1]
    print(linear_search(nums, 231))


main()
