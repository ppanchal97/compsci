def num_guesser():
    high = 100
    low = 0
    is_game_over = False

    while is_game_over == False and low <= high:
        # print guess
        guess = (low + high) / 2
        print(f"Is your secret number {int(guess)}?")
        # take input
        i = input("Enter 'h' to indicate the guess is too high. Enter 'l' to indicate the guess is too low. Enter 'c' to indicate I guessed correctly.")
        # change state based on input
        if i == 'c':
            print(f"Game over. Your secret number was: {int(guess)}")
            is_game_over = True
            return
        elif i == 'h':
            high = guess
        elif i == 'l':
            low = guess
        else:
            print("Sorry, I did not understand your input.")

    print("You picked a number that was not between 0 and 100 exclusive.")


def main():
    num_guesser()


main()
