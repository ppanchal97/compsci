def validate_string(s):
    alphanumeric_characters = False
    alphabetical_characters = False
    digit_characters = False
    lower_case_characters = False
    upper_case_characters = False

    for i in s:
        if i.isalnum():
            alphanumeric_characters = True
            if i.isalpha():
                alphabetical_characters = True
                if i.islower():
                    lower_case_characters = True
                elif i.isupper():
                    upper_case_characters = True
            if i.isnumeric():
                digit_characters = True

    print(alphanumeric_characters)
    print(alphabetical_characters)
    print(digit_characters)
    print(lower_case_characters)
    print(upper_case_characters)


if __name__ == '__main__':
    s = input()
    str_len = len(s)
    if str_len > 0 and str_len < 1000:
        validate_string(s)
    else:
        print("err: input does not satisfy constraints")
