import textwrap

def wrap(string, max_width):
    n = 0
    for i in range(0, len(string)):
        print(string[i], end='')
        n += 1
        if n == max_width:
            n = 0
            print('')

if __name__ == '__main__':
    string, max_width = input(), int(input())
    wrap(string, max_width)