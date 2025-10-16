class Solution:
    def findSmallestInteger(self, nums: List[int], val: int) -> int:
        arr = []
        for n in nums:
            arr.append(n % val) 
        from collections import defaultdict
        mod = defaultdict(int)
        for a in arr:
            mod[a] += 1
        k = min(mod[i] for i in range(val))
        for i in range(0, val):
            if k == mod[i]:
                return  i + (k)*val
        return k*val

        