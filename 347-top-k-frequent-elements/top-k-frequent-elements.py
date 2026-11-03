from collections import Counter
import heapq
class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        counts = Counter(nums)
        h = []
        for x, c in counts.items():
            heapq.heappush(h,(c,x))
            if(len(h) > k): 
                heapq.heappop(h)
        return [x for c, x in h]