class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = Counter(nums)
        print(freq)
        
        min_heap = []
        for val, cnt in freq.items():
            heapq.heappush(min_heap, (cnt, val))
            if len(min_heap) > k:
                heapq.heappop(min_heap)
        return [val for cnt, val in min_heap]