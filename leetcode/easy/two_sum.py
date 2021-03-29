class Solution:
    # type hints
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        hash_set = set()
        positions = []
        for i in range(0, len(nums)):
            c = target - nums[i]
            # find complement in hashset
            if nums[i] in hash_set:
                positions.append(nums.index(target - nums[i]))
                positions.append(i) # current num
                return positions
            else:
                hash_set.add(c)
        return False

l = [2,7,11,15]
target = 9
s = Solution()
print(s.twoSum(l, target))
