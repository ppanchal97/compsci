"""
 Aliasing can be a significant issue in the context of mutations in Python, particularly when working
 with mutable objects such as lists or dictionaries.

 In Python, aliasing occurs when two or more variables refer to the same object in memory. This means
 that if you make a change to the object through one variable, the change will be reflected in all other variables that reference that object.
"""

def sort_pair_aliased(t):
    if t[1] > t[0]:
        return t
    else:
        return [t[1], t[0]]

def sort_pair_no_aliased(t):
    if t[1] > t[0]:
        return [t[0], t[1]]
    else:
        return [t[1], t[0]]


def main():
    t1 = [1, 2]
    t2 = [10, 3]

    print(f"The id of t1 is {id(t1)}, the id of sorted t1 is {id(sort_pair_aliased(t1))} they are {'the same' if id(t1) == id(sort_pair_aliased(t1)) else 'not the same'}")
    print(f"The id of t2 is {id(t2)}, the id of sorted t2 is {id(sort_pair_aliased(t2))} they are {'the same' if id(t2) == id(sort_pair_aliased(t2)) else 'not the same'}")

    # Created an alias. Mutation here also affects all previous declarations of t1
    t3 = sort_pair_aliased(t1)
    t3[0] = 100
    print(t1)
    print(t3)

    # Demonstrates no aliasing
    t4 = sort_pair_no_aliased(t1)
    t4[0] = 50
    print(t1)
    print(t4)


main()
