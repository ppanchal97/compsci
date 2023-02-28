def is_in(s, low, high, target):
    # base cases
    if low > high:
        return False
    elif len(s) == 0:
        return False
    elif len(s) == 1 and s[0] == target:
        return True
    else:
        mid = (low + high) // 2

        if ord(s[mid]) == ord(target):
            return True
        elif ord(s[mid]) > ord(target):
            return is_in(s, low, mid - 1, target)
        else:
            return is_in(s, mid + 1, high, target)


def main():
    s = "bcdgmmnoppppry"
    print(is_in(s, 0, len(s) - 1, 'a'))


main()
