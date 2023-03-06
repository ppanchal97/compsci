def f(x):
    x += 1
    return x

def g(y):
    print(x)
    print(x + 1)


def main():
    x = 3
    print("y()")
    z = f(x)
    print(x)  # 3
    print(z)  # 4

    print("g()")
    g(5)

main()