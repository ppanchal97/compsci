def get_unique_sorted_list(l):
    unique_list = []
    for i in l:  # O(n)
        if not i in unique_list:  # O(n)
            unique_list.append(i)
    return sorted(unique_list)


if __name__ == '__main__':
    students = []
    scores = []
    names = []
    n = int(input())
    if(n >= 2 and n <= 5):
        for _ in range(n):  # O(n)
            name = input()
            score = float(input())
            scores.append(score)
            students.append([name, score])
    else:
        print("err: input does not satisfy constraints")
    unique_scores = get_unique_sorted_list(scores)
    runner_up_score = unique_scores[1]
    # find names
    for student in students:  # O(n)
        if student[1] == runner_up_score:
            names.append(student[0])

    for name in sorted(names):
        print(name)
