class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = Counter(nums)
        print(freq)
        sorted_keys = sorted(freq.keys(), key=lambda x:freq[x], reverse=True)

        print(sorted_keys)

        return sorted_keys[:k]