def is_leap(year):
    leap = False
    if(year % 4 == 0):
        leap = True
        if(year % 100 == 0):
            leap = False
            if year % 400 == 0:
                leap = True
    return leap


if __name__ == '__main__':
    year = int(input())
    if(year >= 1900 and year <= 10**5):
        print(is_leap(year))
    else:
        print("err: input does not satisfy constraints")
