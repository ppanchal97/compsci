#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the repeatedString function below.


def repeatedString(s, n):
    a_count = 0
    a_count_s = s.count('a')
    if len(s) == 1:
        a_count = a_count_s * n
    elif n % len(s) == 0:
        a_count = a_count_s * (n // len(s))
    else:
        extra_chars = n % len(s)
        extra_a_count = s[0: extra_chars].count('a')  # inclusive
        a_count = extra_a_count + a_count_s * (n // len(s))
        
    return a_count


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    n = int(input())

    result = repeatedString(s, n)

    fptr.write(str(result) + '\n')

    fptr.close()
