def factorial_iter(n):
    counter = 1
    num = 1
    while num <= n:
        counter = counter * num
        num += 1
    return counter


def fact(n):
    '''
    f(x) == x * f(x - 1)
    '''
    # known base case - factorial of 1 is 1
    if n == 1:
        return 1
    # recursive step
    else:
        return n * fact(n - 1)


if __name__ == '__main__':
    print(factorial_iter(4))
    print(fact(12))
