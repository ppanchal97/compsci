from __future__ import annotations
import typing

import unittest


class BinarySearchTest(unittest.TestCase):
    def test_binary_search_valid_input(self):
        self.assertEqual(Solution.binary_search(
            ['a', 'b', 'c', 'd', 'e', 'f'], 'b'), True, "Must be True")

    def test_binary_search_invalid_input(self):
        self.assertEqual(Solution.binary_search(
            ['a', 'b', 'c', 'd', 'e', 'f'], 'u'), False, "Must be False")

    def test_binary_search_empty_input(self):
        self.assertEqual(Solution.binary_search(
            [], 'u'), None, "Must be None")


class Solution():
    def binary_search(arr: typing.List[int], target: int) -> bool:
        if len(arr) == 0:
            return None
        right = len(arr) - 1
        left = 0
        while left <= right:
            mid = (right + left) // 2
            # check mid index
            if arr[mid] == target:
                return True
            elif arr[mid] < target:
                left = mid + 1
            elif arr[mid] > target:
                right = mid - 1
        return False


if __name__ == '__main__':
    unittest.main()
