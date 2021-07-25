from __future__ import annotations

from typing import Dict, List

import unittest

expectedOutput = """\
==== Just Falafs ====
      ~ Menu ~
Starters
dumplings, peanuts or salad
Mains
bento, sushi, pasta or rice
Desserts
apples, strawberries or cheese
"""

food_categories = {
    "starters": [
        "peanuts", "bread", "salad", "dumplings"
    ],
    "mains": [
        "steak", "bento", "chicken", "pizza", "sandwich", "taco", "sushi",
        "burger", "hotdog", "pasta", "wrap", "rice"
    ],
    "desserts": [
        "apples", "strawberries", "cheese", "icecream", "pie", "cake"
    ]
}

chef_dishes = [
    "strawberries", "dumplings", "pasta", "rice", "apples", "salad", "peanuts",
    "cheese", "bento", "sushi"
]

class Solution():
    def menuBuilder(food_categories: Dict[str, List], chef_dishes: List[str]) -> None:
        """
        Given a hash_map of food categories and a list of dishes that a chef can make, print the menu to stdout
        """
        courses = ["Starters", "Mains", "Desserts"]
        print("==== Just Falafs ====")
        print("~ Menu ~")
        for course in courses:
            print(course)
            foods_in_category = food_categories[course.lower()]
            servable_foods = list(
                set(foods_in_category).intersection(set(chef_dishes)))
            line_item = []
            for i in range(len(servable_foods) - 1):
                line_item.append(servable_foods[i])
                line_item.append(", ")

            last_item = f" or {servable_foods[-1]}"
            line_item.append(last_item)
            line_item = line_item[:-2] + line_item[-1:]
            print(''.join(line_item))


# function menuBuilder(food_categories: typing.Dict, chef_dishes: typing.List[str]) -> None:
    # initialise a list of courses = ["starters", "mains", "desserts"]
    # iterate over courses:
        # print name of course
        # access array of food_categories based upon course name as key
        # extract unique items from the chef_dishes set that also occur in the course_name set and print using print("", end=", ")
        # enforce that every deleanator is a comma apart from the last one is the string "or"
        # print("\n")

if __name__ == "__main__":
    Solution.menuBuilder(food_categories, chef_dishes)
