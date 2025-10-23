class Solution:
    def hasSameDigits(self, s: str) -> bool:
        if len(s) == 2:
            if s[0] == s[1]:
                return True
            else:
                return False
        else:
            s_new = ""
            for i in range(0, len(s)-1):
                s_new = s_new + str((int(s[i]) + int(s[i+1]))%10)
            return self.hasSameDigits(s_new)
