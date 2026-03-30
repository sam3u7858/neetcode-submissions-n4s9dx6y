from collections import defaultdict
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        count = defaultdict(int)
        for c in s: count[c]+=1
        for c in t: count[c]-=1
        
        return all(v == 0 for v in count.values());