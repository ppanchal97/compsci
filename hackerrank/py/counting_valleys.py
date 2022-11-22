#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'countingValleys' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER steps
#  2. STRING path
#


def countingValleys(steps, path):
    # normalize path
    int_path = []
    sl = 0
    
    # quantify steps
    for i in path:
        if i == 'D':
            sl -= 1
            int_path.append(sl)
        else:
            sl += 1
            int_path.append(sl)

    vc = 0
    for i in range(0, len(int_path)):
        if int_path[i] == 0:
            if int_path[i - 1] < 0:
                vc += 1
    return vc


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    steps = int(input().strip())

    path = input()

    result = countingValleys(steps, path)

    fptr.write(str(result) + '\n')

    fptr.close()
