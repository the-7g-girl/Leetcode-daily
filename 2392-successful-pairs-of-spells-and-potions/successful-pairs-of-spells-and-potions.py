class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        import bisect
        potions.sort()
        ans = []
        n = len(potions)
        for s in spells:
            num = bisect_left(potions, success/s)
            ans.append(n-num)
        return ans
