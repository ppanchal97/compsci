def grid_paths(n, m):
    # base case
    if n == 1 or m == 1:
        return 1
    # recursive step
    else:
        return grid_paths(n - 1, m) + grid_paths(n, m - 1)


if __name__ == '__main__':
    print(grid_paths(3, 3))
