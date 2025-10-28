class Solution:
    def countValidSelections(self, nums: List[int]) -> int:
        n = len(nums)
        pos = []
        
        for i, ele in enumerate(nums):
            if ele == 0:
                pos.append(i)
        
        tot = sum(nums)
        count = 0
        
        for i in pos:
            left_sum = sum(nums[:i])
            right_sum = tot - left_sum
            
            if left_sum == right_sum:
                count += 2
            elif abs(left_sum - right_sum) == 1:
                count += 1
        
        return count