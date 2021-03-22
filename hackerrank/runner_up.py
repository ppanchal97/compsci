if __name__ == '__main__':
    n = int(input())
    arr = map(int, input().split())
    unique_arr = list(set(arr))
    sorted_unique_arr = sorted(unique_arr)
    print(sorted_unique_arr[-2])