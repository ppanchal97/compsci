def main():
    height = int(input("height: "))
    width = int(input("width"))

    for i in range(height):
        for j in range(width):
            print("#", end="")
        print("")

main()