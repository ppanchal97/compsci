#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the minimumBribes function below.


def minimumBribes(q):
    count_bribes = 0
    # prepare expected queue
    exp = []
    for i in range(1, len(q) + 1):
        exp.append(i)

    for i in range(0, len(q)):
        if not q[i] == exp[i]:  # shifted
            diff = q[i] - exp[i]
            if not diff > 2:
                count_bribes += diff
                if diff == 1:
                    exp[i + 1] = exp[i]
                elif diff == 2:
                    exp[i + 2] = exp[i + 1]
                    exp[i + 1] = exp[i]
            else:
                print("Too chaotic")
    print(count_bribes)


if __name__ == '__main__':
    t = int(input())

    for t_itr in range(t):
        n = int(input())

        q = list(map(int, input().rstrip().split()))

        minimumBribes(q)
