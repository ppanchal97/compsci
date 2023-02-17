from math import tan, pi


def polysum(n, s):
    """
    n: number of sides of a regular polygon
    s: length of each side
    """
    area = (0.25*n*s**2)/tan(pi / n)
    perimeter = n * s

    sum = area + perimeter*perimeter

    return round(sum, 4)


def main():
    print(polysum(4, 6))


main()
