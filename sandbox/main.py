import unittest


class TestSum(unittest.TestCase):
    def test_sum(self):
        self.assertEqual(sum([3,3]), 6, "Should be 6")

    def test_sum_tuple(self):
        self.assertEqual(sum((3,2,4)), 5, "Should be 9")


def sum(iterable) -> int:
    sum = 0
    if len(iterable) == 0:
        return 0 
    else:
        for i in iterable:
            sum += i
    return sum


if __name__ == "__main__":
    print(sum([1,2,3,4,5]))
    unittest.main()
