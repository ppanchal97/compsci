# input
# a greeting of n number of string words


# output
# string of a varying dollar amount

###

# take user input

# considerations - case of characters, punctuation, whitespace

# lowercase greeting. Split on whitespace.

# inspect first word in greeting

# if first character in first word is 'h':
    # if first word is 'hello':
        # output $0
    # else output $20
# output $100

greeting = input("greeting: ")
greeting = greeting.lower()
greeting = greeting.split(" ")

if greeting[0][0] == 'h':
    if 'hello' in greeting[0]:
        print("$0")
    else:
        print("$20")
else:
    print("$100")