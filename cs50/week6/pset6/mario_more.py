def main():
    height = int(input("Height: "))
    for row in range(0, height):
        # print spaces
        for i in range(0, height - 1 - row):
            print(" ", end="")
        # print hashes
        for j in range(0, row + 1):
            print("#", end="")
        # print space
        print(" ", end="")
        # print hashes
        for j in range(0, row + 1):
            print("#", end="")
        # print newline
        print("")

main()