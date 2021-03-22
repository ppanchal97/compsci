def fibonacci(n):
    # base case
    if n == 1 or n == 0:
        return 1
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)

print(fibonacci(3))