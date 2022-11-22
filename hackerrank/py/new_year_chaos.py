from __future__ import annotations
from typing import List

import unittest


class TestMinimumBribes(unittest.TestCase):
    def test_minimum_bribes_valid_input_1(self):
        self.assertEqual(Solution.minimumBribes(
            [1, 2, 3, 5, 4, 6, 7, 8]), 1, "Should equal 1")

    def test_minimum_bribes_valid_input_1(self):
        self.assertEqual(Solution.minimumBribes(
            [2, 1, 5, 3, 4]), 3, "Should equal 3")

    def test_minimum_bribes_empty_list(self):
        self.assertEqual(Solution.minimumBribes([]), 0, "Should equal 0")

    def test_minimum_bribes_chaotic_input_1(self):
        self.assertEqual(Solution.minimumBribes(
            [4, 1, 2, 3]), 0, "Should equal 0")

    def test_minimum_bribes_chaotic_input_2(self):
        self.assertEqual(Solution.minimumBribes(
            [2, 5, 1, 3, 4]), 0, "Should equal 0")


class Solution():
    def minimumBribes(q: List[int]) -> int:
        """
        Given an array list of a queue, determine how many bribes took place
        """
        # initialise bribe_counter
        bribe_counter = 0
        # initialise seen_hash_set
        seen_hash_set = set()
        # set expected value, always 1
        expected_value = 1
        # check if list is empty
        if len(q) == 0:
            return 0
        # traverse q:
        for i in q:
            # get actual value and subtract expected from actual
            bribes = i - expected_value
            # if diff > 2: print Too Chaotic and return
            if bribes > 2:
                return 0  # Too Chaotic
            # else: increment bribe_counter
            else:
                bribe_counter += bribes
                # insert actual value into seen_hash_set
                seen_hash_set.add(i)
                # take lowest set difference between seen_hash_set and q and set that as the next expected value
                if len(q) == len(seen_hash_set):
                    # reached the end, return
                    return bribe_counter
                else:
                    expected_value = min(set(q) - seen_hash_set)


if __name__ == '__main__':
    unittest.main()
