class Solution:
    def isZero(self, n: int) -> bool:
        num = n
        if num == 0:
            return True
        while num != 0:
            if num % 10 == 0:
                return True
            num = num // 10
        return False

    def getNoZeroIntegers(self, n: int) -> List[int]:
        for i in range(1, n + 1):
            if not self.isZero(i) and not self.isZero(n - i):
                return [i, n - i]
