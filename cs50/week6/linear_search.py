import sys

nums = [1, 2, 3, 4, 5, 123, 234, 6]

num = int(input("num: "))

if num in nums:
    print("found")
    sys.exit(0)
else:
    print("not found")
    sys.exit(1)