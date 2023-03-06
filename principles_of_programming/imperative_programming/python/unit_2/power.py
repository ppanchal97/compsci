# Recursive approach
def power_recursive(base, exp):
    if exp == 0:
        return 1

    if exp == 1:
        return base

    return base * power_recursive(exp - 1)


# Iterative approach
def power_iterative(base, exp):
    if exp == 0:
        return 1

    product = base

    for i in range(exp - 1):
        product *= base

    return product


def main():
    base = 4
    exp = 15
    print(power_iterative(base, exp))
    print(power_iterative(base, exp))


main()
