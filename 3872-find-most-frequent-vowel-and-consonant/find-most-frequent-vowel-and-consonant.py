class Solution:
    def maxFreqSum(self, s: str) -> int:
        s = s.lower()
        vowels = {}
        cons = {}
        for c in string.ascii_lowercase:
            if c in "aeiou":
                vowels[c] = s.count(c)
            else:
                cons[c] = s.count(c)
        return max(vowels.values()) + max(cons.values())