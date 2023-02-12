def main():
    s = input("s: ")
    t = input("t: ")

    print(f"s is at memory address {id(s)}")
    print(f"t is at memory address {id(t)}")

    print(f"{'Same' if s == t else 'Different'} String")

    print(f"{'Same' if s is t else 'Different'} Memory Address")


main()