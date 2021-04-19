from random import randrange


def load_word():
    words = ['else', 'treat', 'tact']
    random_int = randrange(len(words))
    print("Loading word list from file...")
    print(f"{len(words)} words loaded.")
    w = words[random_int]
    print("Welcome to the game, Hangman!")
    print(f"I am thinking of a word that is {len(w)} letters long.")
    return w


def modify_guessed_chars(guessed_chars, chosen_word, guess):
    veiled_string = list(guessed_chars)
    for i in range(0, len(chosen_word)):
        if chosen_word[i] == guess:
            veiled_string[i] = guess
    return "".join(veiled_string)


def update_available_letters(available_letters, letter_to_remove):
    l = list(available_letters)
    if letter_to_remove in l:
        l.remove(letter_to_remove)
    return "".join(l)


if __name__ == '__main__':
    is_won = False
    available_guesses = 8
    available_letters = 'abcdefghijklmnopqrstuvwxyz'

    chosen_word = load_word()
    guessed_chars_list = []
    guessed_chars = "_" * len(chosen_word)
    guessed_word_count = 0

    while is_won == False and available_guesses > 0:
        print(f"You have {available_guesses} guesses left.")
        print(f"Available letters: {available_letters}")
        guess = input("Please guess a letter: ")
        if guess not in guessed_chars_list:
            guessed_chars_list.append(guess)
            if guess not in chosen_word:
                available_guesses -= 1
                print(f"Oops! That letter is not in my word: {guessed_chars}")
            else:
                guessed_word_count += chosen_word.count(guess)
                if guessed_word_count == len(chosen_word):
                    is_won = True
                guessed_chars = modify_guessed_chars(
                    guessed_chars, chosen_word, guess)
                print(f"good guess: {guessed_chars}")
                available_letters = update_available_letters(
                    available_letters, guess)
        else:
            print("Oops! You've already guessed that letter:")

    if is_won:
        print("Congratulations, you won!")
    else:
        print(f"Sorry, you ran out of guesses. The word was {chosen_word}.")
