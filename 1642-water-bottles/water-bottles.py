class Solution:
    def numWaterBottles(self, n: int, ex: int) -> int:
        ans = 0
        while n >= ex:
            k = n // ex
            ans += k * ex
            n -= k * ex
            n += k
        return ans + n
