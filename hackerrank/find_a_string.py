def count_substring(string, sub_string):
    str_len = len(string)
    sub_str_len = len(sub_string)
    counter = 0
    string_to_check = ''

    # iterate over string
    for i in range(0, len(string)):
        # land on a char that is the same as the first of the sub_string
        if sub_string[0] == string[i]:
            # check next n characters without going out of index
            if not i + sub_str_len > str_len:
                for j in range(i, i + sub_str_len):
                    string_to_check += string[j]
                if string_to_check.strip() == sub_string:
                    counter += 1
                string_to_check = ''

    return counter

if __name__ == '__main__':
    string = input().strip()
    sub_string = input().strip()
    
    count = count_substring(string, sub_string)
    print(count)