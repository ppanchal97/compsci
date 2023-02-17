def power(x, y):
    if y == 1:
        return x

    return x * power(x, y - 1)


x = 3
print(power(x, 5))
print(x**5)