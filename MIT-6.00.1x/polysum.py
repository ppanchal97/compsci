from math import pi, tan


def polysum(n, s):
    a = ((0.25 * n) * (s ** 2)) / tan(pi / n)
    p = (n * s) ** 2
    return round(a + p, 4)


if __name__ == "__main__":
    print(polysum(26, 89))
