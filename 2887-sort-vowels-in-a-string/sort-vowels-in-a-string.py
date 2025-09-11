class Solution:
    def sortVowels(self, s: str) -> str:
        vowels = []
        positions = []
        for id, c in enumerate(s):
            if c in ['a', 'e', 'i', 'o' ,'u', 'A', 'E', 'I', 'O', 'U']:
                positions.append(id)
                vowels.append(c)

        vowels = sorted(vowels, key=lambda x: ord(x))
        letters = list(s)
        i = 0

        for pos in positions:
            letters[pos] = vowels[i]
            i += 1
        
        return "".join(letters)
        
        