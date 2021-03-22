def mutate_string(string, position, character):
    unzipped_string = [*string]
    unzipped_string[position] = character
    return ''.join(unzipped_string)


if __name__ == '__main__':
    s = input()
    i, c = input().split()
    s_new = mutate_string(s, int(i), c)
    print(s_new)
