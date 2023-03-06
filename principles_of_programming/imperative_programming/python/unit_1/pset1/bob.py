def count_bob(s):
    bob_counter = 0

    for i in range(len(s)):
        if s[i] == 'b' and i + 3 <= len(s):
            if s[i:i+3] == 'bob':
                bob_counter += 1

    print("Number of times bob occurs is: " + str(bob_counter))


def main():
    s = 'bobby'
    count_bob(s)


main()
