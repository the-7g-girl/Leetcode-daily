class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        from collections import defaultdict
        freq = defaultdict(int)
        for n in nums:
            freq[n] += 1
        k = max(freq.values())
        t = sum(1 for f in freq.values() if f == k)
        return t*k