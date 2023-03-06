def permutations(s):
    if len(s) == 1:
        return [s]
    else:
        perms = []
        first_char = s[0]
        permutations_list = permutations(s[1:])
        for perm in permutations_list:
            for i in range(len(perm) + 1):
                new_perm = perm[0:i] + first_char + perm[i:]
                perms.append(new_perm)

        return perms


def main():
    perms = (permutations("bust"))
    print(len(perms))

    for perm in perms:
        print(''.join(perm))


main()
