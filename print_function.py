def print_function(n):
    integers_str = ''
    for i in range(1, n + 1):
        integers_str += str(i)

    print(integers_str)


if __name__ == '__main__':
    n = int(input())
    if n >= 1 and n <= 150:
        print_function(n)
    else:
        print("err: input does not satisfy constraints")
