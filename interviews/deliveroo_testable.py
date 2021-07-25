from __future__ import annotations

from typing import Dict, List

import unittest


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


class Menu():
    def __init__(self, starters, mains, desserts) -> None:
        self.starters = starters
        self.mains = mains
        self.desserts = desserts


class TestMenuBuilder(unittest.TestCase):
    def test_menu_builder_valid_input(self):
        # Given an expected menu
        test_menu = Menu(starters=["dumplings", "peanuts", "salad"], mains=[
                         "bento", "pasta", "rice", "sushi"], desserts=["apples", "cheese", "strawberries"])

        # When a menu is created using the menuBuilder() method
        menu = Solution.menuBuilder(food_categories, chef_dishes)

        # Then assert that they match
        self.assertEqual(menu.starters, test_menu.starters,
                         "Should equal expected starters value")
        self.assertEqual(menu.mains, test_menu.mains,
                         "Should equal expected mains value")
        self.assertEqual(menu.desserts, test_menu.desserts,
                         "Should equal expected desserts value")


class Solution():
    def menuBuilder(food_categories: Dict[str, List], chef_dishes: List[str]) -> Menu:
        """
        Given a hash_map of food categories and a list of dishes that a chef can make, print the menu to stdout
        """
        menu = Menu(starters=[], mains=[], desserts=[])
        menu.starters = list(
            set(food_categories["starters"]).intersection(set(chef_dishes)))
        menu.starters.sort()
        menu.mains = list(
            set(food_categories["mains"]).intersection(set(chef_dishes)))
        menu.mains.sort()
        menu.desserts = list(
            set(food_categories["desserts"]).intersection(set(chef_dishes)))
        menu.desserts.sort()

        return menu


if __name__ == "__main__":
    unittest.main()
