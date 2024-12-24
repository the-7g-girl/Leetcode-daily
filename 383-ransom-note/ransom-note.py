class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        ran = {}
        mag = {}
        for c in ransomNote:
            if(c in ran):
                ran[c]+=1
            else:
                ran[c]=1
        for c in magazine:
            if(c in mag):
                mag[c]+=1
            else:
                mag[c]=1
        
        for key in ran.keys():
            if(key not in mag or mag[key]<ran[key]):
                return False
         
        return True
            

        
            
