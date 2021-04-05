def odd_tuples(t):
    ot = list()  
    for i in range(0, len(t), 2):
        ot.append(t[i])
    return tuple(ot)

if __name__ == "__main__":
    print(odd_tuples(('I', 'am', 'a', 'test', 'tuple')))
