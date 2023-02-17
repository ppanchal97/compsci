def calculate_balance(starting_balance, apr, monthly_repayment, month):
    if month == 0:
        # print(f"Starting balance on month 0 is {starting_balance - monthly_repayment}")
        return starting_balance - monthly_repayment
    else:
        previous_balance = calculate_balance(starting_balance, apr, monthly_repayment, month - 1)
        # calculate interest here and add
        interest = (apr / 12) * previous_balance
        # print(f"Interest is {interest}")
        new_balance = previous_balance + interest
        # print(f"Balance on month {month} is {new_balance}")
        if month == 12:
            return round(new_balance, 2)
        # factor in min repayment
        new_balance -= monthly_repayment
        # print(f"Unpaid balance on month {month} is {new_balance}")
        return new_balance


def main():
    balance = 320000
    annualInterestRate = 0.20
    month = 12

    low = 0
    high = balance

    while low <= high:
        middle = round((low + high) / 2, 2)
        eoy_balance = calculate_balance(balance, annualInterestRate, middle, month)
        if abs(eoy_balance) <= 0.1:
            # found
            print(f"Lowest Payment: {middle}")
            return
        elif  eoy_balance >= 0:
            # too low
            low = middle + 0.01
        else:
            # too much
            high = middle - 0.01



main()