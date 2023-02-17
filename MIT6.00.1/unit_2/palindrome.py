import string


def is_palindrome(s):
    s = s.translate(str.maketrans('', '', string.punctuation))
    s = s.strip()
    if len(s) == 1 or len(s) == 0:
        return True
    else:
        if s[0].lower() == s[-1].lower():
            return is_palindrome(s[1:-1])
        else:
            return False


def main():
    print(is_palindrome("hello, world!"))
    # Napoleon
    print(is_palindrome("Able was I, ere I saw Elba"))
    # Anne Michaels
    print(is_palindrome("Are we not drawn onward, we few, drawn onward to new era?"))


main()
