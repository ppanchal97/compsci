def print_variants(number, spaces_length):
    # decimal # octal # hex (CAPITALIZED) # binary
    print(f"{number:{spaces_length}d} {number:{spaces_length}o} {number:{spaces_length}X} {number:{spaces_length}b}")


def print_formatted(number):
    spaces_length = len(f"{number:b}")
    for i in range(0, number):
        print_variants(i + 1, spaces_length)


if __name__ == '__main__':
    n = int(input())
    print_formatted(n)
