def merge_sorted_lists(l1, l2):
    l3 = []
    while len(l1) > 0 and len(l2) > 0:
        i1 = l1[0]
        i2 = l2[0]
        if i1 > i2:
            l2.remove(i2)
            l3.append(i2)
        elif i1 == i2:
            l2.remove(i2)
            l3.append(i2)

            l1.remove(i1)
            l3.append(i1)
        else:
            l1.remove(i1)
            l3.append(i1)
    # nothing to compare, append non-empty list to l3
    if len(l1) > len(l2):
        for i in l1:
            l3.append(i)
    else:
        for i in l2:
            l3.append(i)
    return l3


if __name__ == "__main__":
    l1 = [5, 6, 10]
    l2 = [1, 3, 5, 17]
    print(merge_sorted_lists(l1, l2))
