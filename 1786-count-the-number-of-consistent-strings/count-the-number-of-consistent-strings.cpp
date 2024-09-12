class Solution {
public:
    bool consi(unordered_set<int> mp, string b){
        for (int i = 0; i < b.size(); i++) {
            if(mp.find(b[i])==mp.end()) return false;
        }
        return true;
    }
    int countConsistentStrings(string a, vector<string>& words) {
        unordered_set<int> mp;
        for(char ch: a){
            mp.insert(ch);
        }
        int ans=0;
        for(string w:words){
            if(consi(mp,w)) ans++;
        }
        return ans;
    }
};