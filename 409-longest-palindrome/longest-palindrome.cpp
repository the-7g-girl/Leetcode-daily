class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(char ch: s){
            mp[ch]++;
        }
        int even=0,odd=0,cnt=0;
        for(auto k:mp){
            if(k.second %2==0) even+=k.second;
            else {odd+=k.second-1; cnt++; } 
        }
        if(cnt>0) odd++;
        return even+odd;
    }
};