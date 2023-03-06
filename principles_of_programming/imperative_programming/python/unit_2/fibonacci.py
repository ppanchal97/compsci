def fib_recursive(n):
    if n == 0 or n == 1:
        return 1
    else:
        return fib_recursive(n - 1) + fib_recursive(n - 2)


def main():
    print(fib_recursive(50))


main()
