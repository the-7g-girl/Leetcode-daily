class Solution:
    def doesAliceWin(self, s: str) -> bool:
        ctr = 0
        for c in s:
            if c in "aeiou":
                ctr += 1
        if ctr == 0:
            return False
        else:
            return True
        
        
        