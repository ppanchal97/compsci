def guess_number():
    print("Please think of a number between 0 & 100")
    low = 0
    high = 100
    while True:
        midpoint = int((low + high) / 2)
        print(f"Is your secret number {int(midpoint)}?")
        # take input
        user_input = input(
            "Enter 'h' to indicate the guess is too high. Enter 'l' to indicate the guess is too low. Enter 'c' to indicate I guessed correctly.")
        if user_input == 'h':
            high = int(midpoint)
        elif user_input == 'l':
            low = int(midpoint)
        elif user_input == 'c':
            print(f"Game over. Your secret number was: {int(midpoint)}")
            break
        else:
            print("Sorry, I did not understand your input.")


if __name__ == '__main__':
    guess_number()
