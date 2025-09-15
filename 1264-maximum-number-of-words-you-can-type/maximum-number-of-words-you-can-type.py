class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        words = text.split()
        count = 0
        for word in words:
            valid = True
            for w in word:
                if valid:
                    if w in brokenLetters:
                        valid = False
            if valid:
                count += 1
        return count
