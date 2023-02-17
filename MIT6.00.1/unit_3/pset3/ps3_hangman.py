# Hangman game
#

# -----------------------------------
# Helper code
# You don't need to understand this helper code,
# but you will have to know how to use the functions
# (so be sure to read the docstrings!)

import random

WORDLIST_FILENAME = "words.txt"


def loadWords():
    """
    Returns a list of valid words. Words are strings of lowercase letters.

    Depending on the size of the word list, this function may
    take a while to finish.
    """
    print("Loading word list from file...")
    # inFile: file
    inFile = open(WORDLIST_FILENAME, 'r')
    # line: string
    line = inFile.readline()
    # wordlist: list of strings
    wordlist = line.split()
    print("  ", len(wordlist), "words loaded.")
    return wordlist


def chooseWord(wordlist):
    """
    wordlist (list): list of words (strings)

    Returns a word from wordlist at random
    """
    return random.choice(wordlist)

# end of helper code
# -----------------------------------


# Load the list of words into the variable wordlist
# so that it can be accessed from anywhere in the program
wordlist = loadWords()


def getAvailableLetters(lettersGuessed):
    '''
    lettersGuessed: list, what letters have been guessed so far
    returns: string, comprised of letters that represents what letters have not
      yet been guessed.
    '''
    all_letters = "abcdefghijklmnopqrstuvwxyz"

    for guess in lettersGuessed:
        list_letters = list(all_letters)
        list_letters.remove(guess)
        all_letters = ''.join(list_letters)

    return all_letters


def get_guessed_word(word, guesses):
    for char in word:
        if char not in guesses:
            word = word.replace(char, '_')

    return word


def hangman(secretWord):
    '''
    secretWord: string, the secret word to guess.

    Starts up an interactive game of Hangman.

    * At the start of the game, let the user know how many 
      letters the secretWord contains.

    * Ask the user to supply one guess (i.e. letter) per round.

    * The user should receive feedback immediately after each guess 
      about whether their guess appears in the computers word.

    * After each round, you should also display to the user the 
      partially guessed word so far, as well as letters that the 
      user has not yet guessed.

    Follows the other limitations detailed in the problem write-up.
    '''

    print("Welcome to the game, Hangman!")

    # initialize guesses, no_guesses, max_guesses, available_letters, correct_guesses
    guesses = []
    no_guesses = 0
    correct_guesses = 0
    max_guesses = 8
    available_letters = getAvailableLetters(guesses)
    guessed = get_guessed_word(secretWord, guesses)

    # tell word info
    print(f"I am thinking of a word that is {len(secretWord)} letters long.")

    while no_guesses < max_guesses:
        print(f"You have {max_guesses - no_guesses} guesses left.")
        if correct_guesses == len(secretWord):
            guessed = get_guessed_word(secretWord, guesses)
            print(f"Good guess: {guessed}")
            print("Congratulations, you won!")
            return

        available_letters = getAvailableLetters(guesses)
        print(f"Available letters: {available_letters}")

        guess = input("Please guess a letter: ")

        if guess in guesses:
            print("Letter already guessed.")
        elif guess in secretWord:
            guesses.append(guess)
            correct_guesses += 1
            guessed = get_guessed_word(secretWord, guesses)
            print(f"Good guess: {guessed}")
        else:
            guessed = get_guessed_word(secretWord, guesses)
            print(f"Oops! That letter is not in my word: {guessed}")
            no_guesses += 1

    print(f"Sorry, you ran out of guesses. The word was {secretWord}.")


secretWord = chooseWord(wordlist).lower()
print(secretWord)
# secretWord = "polished"
hangman(secretWord)
