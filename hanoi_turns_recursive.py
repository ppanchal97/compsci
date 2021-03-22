def hanoi(n):
    # base case
    if n == 1:
        return 1
    # recursive step
    else:
        return 2 * hanoi(n - 1) + 1


if __name__ == '__main__':
    print(hanoi(46))
