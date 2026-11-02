from collections import Counter
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        counts = {}
        for c in s:
            counts[c] = counts.get(c, 0) + 1
        for c in t:
            counts[c] = counts.get(c, 0) - 1
        for v in counts.values():
            if v != 0:
                return False
        return True