from collections import defaultdict
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        count = defaultdict(int)
        for c in s: count[c]+=1
        for c in t: count[c]-=1
        
        for k in count:
            if count[k] != 0:
                return False
        return True