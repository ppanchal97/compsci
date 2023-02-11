# Simulate a sports tournament

import csv
import sys
import random
import math

# Number of simluations to run
N = 1000000


def main():
    # Ensure correct usage
    # if len(sys.argv) != 2:
    #     sys.exit("Usage: python tournament.py FILENAME")

    # dictionary of teams e.g., {"team": "Uruguay", "rating": 976}
    teams = []
    with open('/Users/parik97/Desktop/code/cs50/week6/lab6/world-cup/2018m.csv') as csv_file:
        csv_reader = csv.reader(csv_file, delimiter=',')
        line_count = 0
        for row in csv_reader:
            if line_count == 0:
                print(f"{row[0]}, {row[1]}")
                line_count += 1
            else:
                if len(row) != 0:
                    teams.append({"team": row[0], "rating": int(row[1])})

    # dictionary of wins e.g., {"team": "Uruguay"} where frequency = number of wins
    counts = {}
    for team in teams:
        counts[team['team']] = 0
    
    
    # TODO: Simulate N tournaments and keep track of win counts
    for i in range(N):
        winner_team =  simulate_tournament(teams)
        counts[winner_team['team']] += 1

    print(counts)
    
    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # goal is to get a team that has passed through all the rounds and has won the tournament

    # calculate number of rounds (sqrt of teams)
    # rounds = 0
    # if len(teams) == 2:
    #     rounds = 1
    # elif len(teams) == 3:
    #     rounds = 2
    # else:
    #     rounds = math.sqrt(teams)

    rounds = 4

    # for each round:
    for round in range(rounds):
        # simulate round
        winners = simulate_round(teams)
        # remove losers and update copy teams variable
        teams = winners

    # add winner to counts as {"team": "<TEAM_NAME>"}
    if len(teams) == 1:
        return teams[0]
        


if __name__ == "__main__":
    main()
