def main():
    change_amount = float(input("Change owed: "))
    change_counter = 0

    denominations = [0.25, 0.10, 0.05, 0.01]

    for denomination in denominations:
        while round(change_amount - denomination, 2) >= 0:
            change_amount -= denomination
            change_counter += 1

    print(change_counter)


main()
