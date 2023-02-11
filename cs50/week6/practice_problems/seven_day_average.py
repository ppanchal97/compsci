import csv
import requests

import datetime
from collections import defaultdict


def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


# TODO: Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):
    # {"New York": {"last_7_day_cases": 2134123, "7_days_before_cases": 2134110, "last_case_point": 2323243}}
    state_cases = defaultdict(lambda: {"last_7_day_cases": 0, "7_days_before_cases": 0, "last_case_point": 0})
    for data_point in reader:
        date = datetime.datetime.strptime(data_point["date"], '%Y-%m-%d')
        now = datetime.datetime.now()
        if date >= now - datetime.timedelta(days=14):
            # print(data_point)
            # get state of the data point
            state = data_point["state"]
            # check if state exists in the state_cases dictionary
            if not state in state_cases.keys():
                # no state exists, create and initialize one
                state_cases[state] = {
                    "last_7_day_cases": 0, "7_days_before_cases": 0, "last_case_point": int(data_point["cases"])}
            # check if date is in last 7 days
            if date >= now - datetime.timedelta(days=7):
                state_cases[state]["last_7_day_cases"] += (
                    int(data_point["cases"]) - state_cases[state]["last_case_point"])
                state_cases[state]["last_case_point"] = int(
                    data_point["cases"])
            # else date is in last 14 - 7 days
            elif date <= now - datetime.timedelta(days=7):
                state_cases[state]["7_days_before_cases"] += (
                    int(data_point["cases"]) - state_cases[state]["last_case_point"])
                state_cases[state]["last_case_point"] = int(
                    data_point["cases"])

    return state_cases


# TODO: Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    for state in states:
        # lookup state in cases dict
        state_dict = new_cases[state]
        # calculate and print averages
        seven_day_avg = state_dict["last_7_day_cases"] / 7
        fourteen_day_avg = state_dict["7_days_before_cases"] / 7
        difference = ((seven_day_avg-fourteen_day_avg)/seven_day_avg)*100
        print(f"{state} had a 7-day average of {seven_day_avg:.2f} and {'a decrease' if difference <= 0 else 'an increase'} of {difference:.2f}%")


main()
