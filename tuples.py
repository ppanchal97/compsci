def hash_tuple(t):
    return hash(t)

if __name__ == '__main__':
    n = int(input())
    integer_list = tuple(map(int, input().split()))
    print(hash_tuple(integer_list))