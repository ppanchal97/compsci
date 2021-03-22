def gcd_recur(a, b):
    # base case
    if b == 0:
        return a
    # recursive step
    else:
        return gcd_recur(b, a % b)


if __name__ == "__main__":
    print(gcd_recur(9, 12))
