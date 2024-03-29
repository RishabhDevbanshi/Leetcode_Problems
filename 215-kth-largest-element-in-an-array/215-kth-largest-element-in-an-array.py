class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        heap = []
        for i in range(len(nums)):
            heapq.heappush(heap,nums[i])
            if len(heap) > k:
                heapq.heappop(heap)
        # print(heap)
        return heappop(heap)