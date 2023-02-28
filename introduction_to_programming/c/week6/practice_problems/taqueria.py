import sys

menu = {
    "Baja Taco": 4.00,
    "Burrito": 7.50,
    "Bowl": 8.50,
    "Nachos": 11.00,
    "Quesadilla": 8.50,
    "Super Burrito": 8.50,
    "Super Quesadilla": 9.50,
    "Taco": 3.00,
    "Tortilla Salad": 8.00
}

def main():
    # until user exits, keep taking input
    try:
        total = 0
        while True:
            choice = input("Item: ")
            for key in menu:
                if key.lower() == choice.lower():
                    total += menu[key]
                    print(f"Total: ${total}")
    except EOFError:
        sys.exit(0)


main()