class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        elements = set(nums)
        return len(elements) < len(nums)