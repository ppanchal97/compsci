# Hangman game
#

# -----------------------------------
# Helper code
# You don't need to understand this helper code,
# but you will have to know how to use the functions
# (so be sure to read the docstrings!)

import random
import string

WORDLIST_FILENAME = "words.txt"


def loadWords():
    """
    Returns a list of valid words. Words are strings of lowercase letters.

    Depending on the size of the word list, this function may
    take a while to finish.
    """
    # print("Loading word list from file...")
    # inFile: file
    inFile = open(WORDLIST_FILENAME, 'r')
    # line: string
    line = inFile.readline()
    # wordlist: list of strings
    wordlist = line.split()
    # print("  ", len(wordlist), "words loaded.")
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


def isWordGuessed(secretWord, lettersGuessed):
    '''
    secretWord: string, the word the user is guessing
    lettersGuessed: list, what letters have been guessed so far
    returns: boolean, True if all the letters of secretWord are in lettersGuessed;
      False otherwise
    '''
    for char in secretWord:
        if char not in lettersGuessed:
            return False

    return True


def getGuessedWord(secretWord, lettersGuessed):
    '''
    secretWord: string, the word the user is guessing
    lettersGuessed: list, what letters have been guessed so far
    returns: string, comprised of letters and underscores that represents
      what letters in secretWord have been guessed so far.
    '''
    for char in secretWord:
        if char not in lettersGuessed:
            secretWord = secretWord.replace(char, '_')

    return secretWord


def getAvailableLetters(lettersGuessed):
    '''
    lettersGuessed: list, what letters have been guessed so far
    returns: string, comprised of letters that represents what letters have not
      yet been guessed.
    '''
    all_letters = string.ascii_lowercase
    list_letters = list(all_letters)

    for guess in set(lettersGuessed):
        list_letters.remove(guess)

    all_letters = ''.join(list_letters)

    return all_letters


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

   # initialize guesses, no_guesses, max_guesses, available_letters, correct_guesses
    guesses = []
    no_guesses = 0
    max_guesses = 8
    available_letters = getAvailableLetters(guesses)
    guessed = getGuessedWord(secretWord, guesses)

    print("Welcome to the game Hangman!")

    # tell word info
    print("I am thinking of a word that is " +
          str(len(secretWord)) + " letters long")
    print("-----------")

    while no_guesses < max_guesses:
        print("You have " + str(max_guesses - no_guesses) + " guesses left")
        if isWordGuessed(secretWord, guesses):
            print("Good guess: " + secretWord)
            print("Congratulations, you won!")
            return

        available_letters = getAvailableLetters(guesses)
        print("Available Letters: " + available_letters)

        guess = input("Please guess a letter: ")
        guesses.append(guess)

        if guesses.count(guess) > 1:
            print("Oops! You've already guessed that letter: " +
                  getGuessedWord(secretWord, guesses))
            print("-----------")
        elif guess in secretWord:
            guessed = getGuessedWord(secretWord, guesses)
            print("Good guess: " + guessed)
            print("-----------")
            if isWordGuessed(secretWord, guesses):
                print("Congratulations, you won!")
                return
        else:
            guessed = getGuessedWord(secretWord, guesses)
            print("Oops! That letter is not in my word: " + guessed)
            no_guesses += 1
            print("-----------")

    print("Sorry, you ran out of guesses. The word was " + secretWord + ".")


# When you've completed your hangman function, uncomment these two lines
# and run this file to test! (hint: you might want to pick your own
# secretWord while you're testing)
# secretWord = chooseWord(wordlist).lower()
# print(secretWord)
secretWord = "sea"
hangman(secretWord)
