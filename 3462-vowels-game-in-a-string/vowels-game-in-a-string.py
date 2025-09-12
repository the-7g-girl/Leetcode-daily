class Solution:
    def doesAliceWin(self, s: str) -> bool:
        ctr = 0
        for c in s:
            if c in "aeiou":
                return True
        return False
       
        
        
        