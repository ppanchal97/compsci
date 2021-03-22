def fibonacci(n):
    # base case
    if n == 0:
        return 1
    else:
        return fibonacci(n -1) + fibonacci(n - 2)

n = int(input())
print(fibonacci(n))