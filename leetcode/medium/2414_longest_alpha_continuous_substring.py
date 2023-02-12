class Solution(object):
    def longest_alpha_substring_length(self, s):
        substrings = []
        substring = ""

        for i in range(0, len(s)):
            if i != 0:
                if ord(substring[-1]) <= ord(s[i]):
                    substring += s[i]
                else:
                    if len(substring) > 1:
                        substrings.append(substring)
                    substring = ""
                    substring += s[i]
            else:
                substring += s[i]

            # completely alphabetical string
            if i == len(s) - 1:
                substrings.append(substring)

        # return first largest alphabetical substring
        return len(sorted(substrings, key=len)[-1])


sol = Solution()
print(sol.longest_alpha_substring_length('azcbobobegghakl'))
