def recurPower(base, exp):
    # x^y == x * x * x. y times.
    # base case
    if exp == 1:
        return base
    else:
        return base * recurPower(base, exp - 1)


if __name__ == '__main__':
    print(recurPower(2, 5))
