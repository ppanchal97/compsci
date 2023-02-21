# Memoized implementation
def fib_optimized(n, dict):
    # if computed, look up
    if n in dict:
        return dict[n]
    else:
        # compute then store
        f = fib_optimized(n - 1, dict) + fib_optimized(n - 2, dict)
        dict[n] = f
        return f


# Naive implementation
def fib_recursive(n):
    if n == 0 or n == 1:
        return 1
    else:
        return fib_recursive(n - 1) + fib_recursive(n - 2)


def main():
    # print(fib_recursive(50))

    fibs = {1: 1, 2: 2}
    print(fib_optimized(50, fibs))


main()
