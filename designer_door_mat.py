def print_door_mat(n, m):
    row = 0
    # height
    for i in range(0, n):
        if row < (n - 1) / 2:
            # top half
            symbols_to_print = row * 2 + 1
            dashes_to_print = int((m - symbols_to_print * 3) / 2)
            print(
                f"{dashes_to_print * '-'}{symbols_to_print * '.|.'}{dashes_to_print * '-'}", end='')
            row += 1
            print('')
        elif row == (n - 1) / 2:
            # welcome message
            dashes_to_print = int((m - 7) / 2)
            print(f"{dashes_to_print * '-'}{'WELCOME'}{dashes_to_print * '-'}")
            row += 1
        else:
            # bottom half
            symbols_to_print = n - row + (n - row - 1)
            dashes_to_print = int((m - symbols_to_print * 3) / 2)
            print(
                f"{dashes_to_print * '-'}{symbols_to_print * '.|.'}{dashes_to_print * '-'}", end='')
            row += 1
            print('')


if __name__ == '__main__':
    n, m = map(int,input().split())
    if (n > 5 and n < 101) and (n % 2 != 0 and n > 0):
        if (m > 15 and m < 303) and (m == n * 3):
            print_door_mat(n, m)
