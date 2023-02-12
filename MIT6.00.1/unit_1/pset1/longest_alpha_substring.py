def longest_alpha_substring(s):
    substrings = []
    substring = []

    for i in range(0, len(s)):
        substring.append(s[i])
        # continue appending to substring until next character > current character's integer value
        for j in range(i + 1, len(s)):
            if ord(s[j]) >= ord(substring[-1]):
                substring.append(s[j])
            else:
                # break and append substring to substrings list
                if len(substring) > 1:
                    substrings.append(''.join(substring))
                substring = []
                break

    # return first largest alphabetical substring
    return sorted(substrings, key=len)[-1]


def main():
    s = 'azcbobobegghakl'
    print(longest_alpha_substring(s))


main()
