def main():
    change_amount = float(input("Change owed: "))
    change_counter = 0

    while change_amount != 0:
        if round(change_amount - 0.25, 2) >= 0:
            change_amount = round(change_amount - 0.25, 2)
            change_counter += 1
        elif round(change_amount - 0.10, 2) >= 0:
            change_amount = round(change_amount - 0.10, 2)
            change_counter += 1
        elif round(change_amount - 0.05, 2) >= 0:
            change_amount = round(change_amount - 0.05, 2)
            change_counter += 1
        elif round(change_amount - 0.01, 2) >= 0:
            change_amount = round(change_amount - 0.01, 2)
            change_counter += 1
        else:
            break

    print(change_counter)


main()
