#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the sockMerchant function below.
def sockMerchant(n: int, ar: list[int]) -> int:
    hashmap = {}
    for i in ar:
        if not i in hashmap.keys():
            count = ar.count(i) // 2 # O(n)
            hashmap[i] = count
    # sum
    counter = 0
    for k, v in hashmap.items():
        counter += v
    
    return counter

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    ar = list(map(int, input().rstrip().split()))

    result = sockMerchant(n, ar)

    fptr.write(str(result) + '\n')

    fptr.close()
