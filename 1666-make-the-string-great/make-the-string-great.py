class Solution:
    def makeGood(self, s: str) -> str:
        ans = ""
        i = 0
        while i < len(s):
            print("i", i)
            if i < len(s) - 1 and s[i] != s[i+1] and s[i].lower() == s[i+1].lower():
                i += 2
            else:
                ans = ans + s[i]
                i += 1
        
        if ans == s:
            return ans
        return self.makeGood(ans)
