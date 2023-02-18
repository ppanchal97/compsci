def caesar(s, key):
    if len(s) == 1:
        return chr(ord(s) + key)
    else:
        return caesar(s[0], key) + caesar(s[1:], key)


def main():
    print(caesar("abcdef", 2))


main()
