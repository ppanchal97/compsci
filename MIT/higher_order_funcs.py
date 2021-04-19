def applyToEach(L, f):
    for i in range(len(L)):
        L[i] = f(L[i])


def square(n):
    return n ** 2


if __name__ == "__main__":
    testList = [1, -4, 8, -9]
    applyToEach(testList, abs)
    applyToEach(testList, square)
    print(testList)
    del()