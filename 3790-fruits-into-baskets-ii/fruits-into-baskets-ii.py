class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        ans = 0
        for f in fruits:
            placed = False
            for idx, cap in enumerate(baskets):
                if f <= cap:
                    baskets[idx] = 0
                    placed = True 
                    break
            if not placed:
                ans += 1
        return ans



