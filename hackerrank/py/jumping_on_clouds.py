#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the jumpingOnClouds function below.


def jumpingOnClouds(c):
    j = 0
    cc = 0
    while cc < len(c) - 1:
        if cc == len(c) - 2:
            cc += 1
            j += 1
        elif c[cc + 2] == 0:
            cc += 2
            j += 1
        else:
            cc += 1
            j += 1

    return j


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    c = list(map(int, input().rstrip().split()))

    result = jumpingOnClouds(c)

    fptr.write(str(result) + '\n')

    fptr.close()
