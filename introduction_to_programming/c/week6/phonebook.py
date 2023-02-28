# Program that accepts a name from the user and returns their phone number

# data structure to hold name and numbers
phonebook = {"parik":  "(347)-804-7571",
             "david": "+1-949-468-2750", "carter": "+1-617-495-1000"}

# accept user input
name = input("enter name: ")

# search for the input in the phonebook
for contact in phonebook:
    if name == contact:
        print(phonebook[contact])
