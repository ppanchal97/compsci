# Algorithm
def factorial(n):
    answer = 1

    while n > 1:
        answer *= n
        n -= 1

    return answer

# Analysis
def factorial(n):
    """
    1 + n(1 + 2 + 2) + 1
    = 2 + n(5)
    = 2 + 5n
    Dominant term = n
    """
    # 1 operation to declare and initialize a variable
    answer = 1

    # 1 comparison operation between n and 1, n times
    while n > 1:
        # 1 multiply operation and 1 assign operation
        answer *= n
        # 1 subtract operation and 1 assign operation
        n -= 1

    return answer

def main():
    print(factorial(5))


main()