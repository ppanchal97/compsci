def odd_tuples(aTup):
    '''
    aTup: a tuple

    returns: tuple, every other element of aTup. 
    '''
    returnTup = list()
    for i in range(0, len(aTup), 2):
        returnTup.append(aTup[i])

    return tuple(returnTup)


def main():
    print(odd_tuples(('I', 'am', 'a', 'test', 'tuple')))
    return 0


main()
