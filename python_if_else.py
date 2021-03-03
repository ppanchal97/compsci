#!/bin/python3

import math
import os
import random
import re
import sys


def python_if_else(n):
    if(n >= 1 and n <= 100):
        if n % 2 == 0:
            # even
            if n >= 2 and n <= 5:
                print("Not Weird")
            elif n >= 6 and n <= 20:
                print("Weird")
            elif n > 20:
                print("Not Weird")
        else:
            # odd
            print("Weird")
    else:
        print("input does not satisfy constraint")


if __name__ == '__main__':
    n = int(input().strip())
    python_if_else(n)
