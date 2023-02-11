def main():
    scores = []
    score_count = int(input("number of scores: "))
    for i in range(score_count):
        score = int(input("score: "))
        scores.append(score) # demonstrates OOP methods of a data type

    for i in range(score_count):
        print(scores[i])

    print(f"average is {sum(scores) / len(scores):.2f}")


main()
