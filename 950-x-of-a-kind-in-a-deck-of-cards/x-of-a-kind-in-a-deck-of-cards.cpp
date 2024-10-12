class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> mp;
        for(int k: deck) mp[k]++;
        bool flag=true;
        if(deck.size()==1) return false;
        int t=mp[deck[0]];
        for(auto m :mp){
            t=gcd(t,m.second);
        }
        return t>1;
    }
};