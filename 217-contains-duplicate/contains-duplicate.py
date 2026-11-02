class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        elements = set()
        for x in nums:
            if x in elements:
                return True
            elements.add(x)
        return False