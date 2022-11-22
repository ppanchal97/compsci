def swap_case(s):
    str = ''
    for i in s:
        if i.isalpha():
            if i.isupper():
                str += i.lower()
            elif i.islower():
                str += i.upper()
        else:
            str += i
    return str


if __name__ == '__main__':
    s = input()
    str_len = len(s)
    if str_len > 0 and str_len <= 1000:
        result = swap_case(s)
        print(result)
    else:
        print("err: input does not satisfy constraints")
