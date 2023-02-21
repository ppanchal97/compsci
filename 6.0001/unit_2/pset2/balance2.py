def calculate_balance(starting_balance, apr, monthly_repayment, month):
    if month == 0:
        print(f"Starting balance on month 0 is {starting_balance - monthly_repayment}")
        return starting_balance - monthly_repayment
    else:
        previous_balance = calculate_balance(starting_balance, apr, monthly_repayment, month - 1)
        # calculate interest here and add
        interest = (apr / 12) * previous_balance
        print(f"Interest is {interest}")
        new_balance = previous_balance + interest
        print(f"Balance on month {month} is {new_balance}")
        if month == 12:
            return round(new_balance, 2)
        # factor in min repayment
        new_balance -= monthly_repayment
        print(f"Unpaid balance on month {month} is {new_balance}")
        return new_balance


def main():
    balance = 3926
    annualInterestRate = 0.2
    month = 12

    # Iterate on monthly repayments until balance turns negative
    for i in range(10, balance, 10):
        eoy_balance = calculate_balance(balance, annualInterestRate, i, month)
        if eoy_balance <= 0:
            print("Lowest Payment: " + str(i))
            break


main()
