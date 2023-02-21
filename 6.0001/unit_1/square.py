# Python program to square a given number without using exponents

def square(n):
    ans = 0
    iters_left = n
    while iters_left != 0:
        ans += n
        iters_left -= 1
    
    print(f"{n}*{n} = {ans}")

def main():
    square(4)

main()