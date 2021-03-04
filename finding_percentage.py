def array_average(a):
    sum = 0
    for i in a:  # O(n)
        sum += i
    avg = sum / len(a)  # O(1)
    return avg


if __name__ == '__main__':
    n = int(input())
    student_marks = {}
    for _ in range(n):  # O(n)
        name, *line = input().split()
        scores = list(map(float, line))
        student_marks[name] = scores
    query_name = input()

    for k, v in student_marks.items():  # O(n)
        if k == query_name:
            print(f'{array_average(v):.2f}')
