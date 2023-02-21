def towers_of_hanoi(n, start, end, spare):
    if n == 1:
        # print("Move disk 1 from rod", start, "to rod", end)
        return

    towers_of_hanoi(n-1, start, spare, end)
    # print("Move disk", n, "from rod", start, "to rod", end)
    towers_of_hanoi(n-1, spare, end, start)


def main():
    towers_of_hanoi(64, 1, 3, 2)


main()
