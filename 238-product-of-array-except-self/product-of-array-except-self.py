class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        #idea is to create the prefix and suffix products for each element and then multiply them together
        prefix = [1]
        n = len(nums)
        for i in range(1, n):
            prefix.append(prefix[-1]*nums[i-1])
        suffix = [1]*n
        for i in range(n-2, -1, -1):
            suffix[i] = suffix[i+1]*nums[i+1]
        return [prefix[i]*suffix[i] for i in range(n)]
        