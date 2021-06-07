def exponent_iter(base, exp):
    # x^y == x * x * x. y times.
    counter = base
    for i in range(0, exp - 1):
        counter = counter * base
    return counter


if __name__ == '__main__':
    print(exponent_iter(3, 3))
