def main():
    # accept input
    # cc_number = input("Number: ")
    cc_number = input("Number: ")
    cc = list(reversed(cc_number))

    # reverse iterate the number with a step of 2
    reversed_digits = ""
    for i in range(1, len(cc), 2):
        reversed_digits += str(int(cc[i]) * 2)

    reversed_product = 0
    for c in list(reversed_digits):
        reversed_product += int(c)

    forward_product = 0
    for i in range(0, len(cc), 2):
        forward_product += int(cc[i])

    sum = forward_product + reversed_product

    if sum % 10 == 0:
        if len(cc_number) == 13 and cc_number[0] == "4":
            print("VISA")
        elif len(cc_number) == 15 and (cc_number[:2] == "34" or cc_number[:2] == "37"):
            print("AMEX")
        elif len(cc_number) == 16:
            if int(cc_number[:2]) >= 51 and int(cc_number[:2]) <= 55:
                print("MASTERCARD")
            elif cc_number[0] == "4":
                print("VISA")
    else:
        print("INVALID")


main()
