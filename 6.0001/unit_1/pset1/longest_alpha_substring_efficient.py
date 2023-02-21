def longest_alpha_substring(s):
    substrings = []
    substring = []

    for i in range(0, len(s)):
        if i != 0:
            if ord(substring[-1]) <= ord(s[i]):
                substring.append(s[i])
            else:
                if len(substring) > 1:
                    substrings.append(''.join(substring))
                substring = []
                substring.append(s[i])
        else:
            substring.append(s[i])

        # completely alphabetical string
        if i == len(s) - 1:
            substrings.append(''.join(substring))

    # return first largest alphabetical substring
    return sorted(substrings, key=len)[-1]


def main():
    s = 'azcbobobegghakl'
    print(f"Longest substring in alphabetical order is: {longest_alpha_substring(s)}")


main()
