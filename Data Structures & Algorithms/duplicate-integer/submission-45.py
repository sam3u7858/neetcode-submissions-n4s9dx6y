class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        has_dup = {}

        for n in nums:
            if n in has_dup:
                return True
            has_dup[n] = True
        return False