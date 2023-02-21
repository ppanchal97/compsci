def calculate_balance(starting_balance, apr, minimum_rate, month):
    if month == 0:
        print(f"Starting balance on month 0 is {starting_balance - starting_balance * minimum_rate}")
        return starting_balance - starting_balance * minimum_rate
    else:
        previous_balance = calculate_balance(starting_balance, apr, minimum_rate, month - 1)
        # calculate interest here and add
        interest = (apr / 12) * previous_balance
        print(f"Interest is {interest}")
        new_balance = previous_balance + interest
        print(f"Balance on month {month} is {new_balance}")
        if month == 12:
            return round(new_balance, 2)
        # factor in min repayment
        new_balance -= new_balance * minimum_rate
        print(f"Unpaid balance on month {month} is {new_balance}")
        return new_balance


def main():
    balance = 5000
    annualInterestRate = 0.18
    monthlyPaymentRate = 0.02
    month = 12
    print("Remaining balance: " + str(calculate_balance(balance, annualInterestRate, monthlyPaymentRate, 12)))


main()
