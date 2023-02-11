def main():
    sentence = "Would you like them here or there? I would not like them here or there. I would not like them anywhere."
    letter_count = 0
    word_count = 0
    sentence_count = 0

    for c in list(sentence):
        if c.isalpha():
            letter_count += 1
        elif c == " ":
            word_count += 1
        elif c == "." or c == "!" or c == "?":
            sentence_count += 1

    grade = 0.0588 * letter_count / \
        (word_count + 1) * 100 - 0.296 * \
        sentence_count / (word_count + 1) * 100 - 15.8

    print(f"{letter_count} letters")
    print(f"{word_count + 1} words")
    print(f"{sentence_count} sentences")

    print(f"Grade {round(grade)}")


main()
