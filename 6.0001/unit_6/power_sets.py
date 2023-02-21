nums = [1, 2, 3, 4]

power_sets = set()

for i in range(len(nums)):
    s = []
    for j in range(len(nums)):
        s.append(nums[i])
        s.append(nums[j])
        power_sets.add(s)
        s.clear()

print(power_sets)
