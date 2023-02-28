def count_vowels(s):
    vowel_counter = 0

    for char in s:
        if char in ['a', 'e', 'i', 'o', 'u']:
            vowel_counter += 1

    print(f"Number of vowels: {vowel_counter}")


def main():
    s = 'azcbobobegghakl'
    count_vowels(s)


main()
