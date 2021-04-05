#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the rotLeft function below.
def rotLeft(a, n):
    # rotated array
    ra = []

    # determine mean rotations
    if n > len(a):
        n = n % len(a)

    # extract len - n
    for i in range(n, len(a)):
        ra.append(a[i])

    # append 0 : mean chars to end of rotated array
    for i in range(0, n):
        ra.append(a[i])

    return ra


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nd = input().split()

    n = int(nd[0])

    d = int(nd[1])

    a = list(map(int, input().rstrip().split()))

    result = rotLeft(a, d)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
