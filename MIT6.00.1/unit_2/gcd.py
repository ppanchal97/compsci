# Recursive implementation for deriving greatest common denominator
def gcd_recursive(a, b):
    if b == 0:
        return a
    else:
        return gcd_recursive(b, a % b)


# Iterative implementation for deriving greatest common denominator
def gcd_iterative(a, b):
    divisor = min(a, b)

    while divisor != 1 and (a % divisor != 0 or b % divisor != 0):
        divisor -= 1

    return divisor


def main():
    print(gcd_recursive(17, 12))
    print(gcd_iterative(17, 12))


main()
