def is_palindrome(string):
    # base cases
    if len(string) == 1:
        return True
    elif string[0] != string[-1]:
        return False
    # recursive step
    else:
        # clip first and last letters
        trimmed_string = string[1:-1]
        return is_palindrome(trimmed_string)

if __name__ == '__main__':
    print(is_palindrome('racecar'))