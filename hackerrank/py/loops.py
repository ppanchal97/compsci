def loop_and_square(n):
    for i in range(0, n):
        print(i**2)


if __name__ == '__main__':
    n = int(input())
    if(n >= 1 and n <= 20):
        loop_and_square(n)
    else:
        print("err: input does not satisfy constraints")
