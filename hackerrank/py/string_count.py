from __future__ import annotations

import typing

import unittest

# ----------------
# For a given string of letters, count occurrences of each and print them out. For instance:
# count('hello') => h: 1, e: 1, l: 2, o: 1

# _Constraints_
# return a hashmap k-character, v-counts such that given input = 'hello', then output = {h: 1, e: 1, l: 2, o: 1}
# All return keys must be of type string
# given input = '', output = {}
# given input = None, output = {}
# -----------------


class CountTest(unittest.TestCase):
    def test_count_valid_string(self):
        self.assertEqual(Solution.count("hello"), {
                         "h": 1, "e": 1, "l": 2, "o": 1}, "Should be {h: 1, e: 1, l: 2, o: 1}")

    def test_count_empty_string(self):
        self.assertEqual(Solution.count(""), {}, "Should be empty hash_map")

    def test_count_none_input(self):
        self.assertEqual(Solution.count(None), {}, "Should be empty hash_map")


class Solution():
    def count(s: str) -> typing.Dict[str, int]:
        """
        Accepts a string of arbitrary length and returns a hashmap containing the counts
        of all characters, ignoring letter casing.
        """
        # assert s is not None, return {}
        if s is None:
            return {}
        # assert len(s) > 0,return {}
        if len(s) == 0:
            return {}
        # initialise character count hash_map "c_count"
        c_count = dict()
        # iterate over s:
        for i in s:
            # check if char is a key in c_count O(1) lookup
            if i.lower() in c_count:
                # increment the value of the character in c_count
                c_count[i.lower()] += 1
            else:
                # if does not exist, insert k-v pair of {char: 1}
                c_count[i.lower()] = 1

        return c_count


if __name__ == "__main__":
    unittest.main()
