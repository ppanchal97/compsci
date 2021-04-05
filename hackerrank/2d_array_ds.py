#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the hourglassSum function below.


def hourglassSum(arr):
    # hourglass counts, optimal as binary heap
    counts = []

    for i in range(0, 4):  # first 4 rows
        for j in range(0, 4):  # first 4 columns
            hc = 0
            # top
            hc += arr[i][j]
            hc += arr[i][j + 1]
            hc += arr[i][j + 2]
            # link
            hc += arr[i + 1][j + 1]
            # bottom
            hc += arr[i + 2][j]
            hc += arr[i + 2][j + 1]
            hc += arr[i + 2][j + 2]

            counts.append(hc)

    max_count = max(counts)

    return max_count


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    arr = []

    for _ in range(6):
        arr.append(list(map(int, input().rstrip().split())))

    result = hourglassSum(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
