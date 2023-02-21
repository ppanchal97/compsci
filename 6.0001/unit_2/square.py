def search_root(n):
    # adjust tolerance using epsilon
    epsilon = 0.00000000000000001
    low = 0
    high = n
    num_guesses = 0

    while low <= high:
        guess = (low + high) / 2
        num_guesses += 1
        print(f"new guess: {guess}")
        print(f"differential: {abs(guess**2-n)}")
        if abs(guess**2-n) <= epsilon:
            print(
                f"the square root is {guess}. Found in {num_guesses} guesses.")
            break
        elif (guess**2-n) >= epsilon:
            high = guess
        else:
            low = guess


def main():
    search_root(25)


main()
