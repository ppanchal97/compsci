def count_partitions(n, m):
    # base case
    if m == 1:
        return 1
    # recursive step
    else:
        return (n - m) + count_partitions(n, m - 1)

if __name__ == "__main__":
    print(count_partitions(9, 2))