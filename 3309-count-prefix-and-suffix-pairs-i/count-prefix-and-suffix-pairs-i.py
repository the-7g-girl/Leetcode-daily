class Solution:
    def isPrefixAndSuffix(self,a, b):
        na=len(a)
        nb=len(b)
        if a==b[0:na] and a==b[nb-na:nb]:
            return True
        else:
            return False

    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        n=len(words)
        count=0
        for i in range(n):
            for j in range(i+1,n):
                if(Solution().isPrefixAndSuffix(words[i],words[j])):
                    count+=1
        return count
        