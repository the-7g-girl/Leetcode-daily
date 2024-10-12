class Solution {
public:
    int gcdfun(int a, int b){
        if(b>a) swap(a,b);
        while(b!=0){
            int t=a%b;
            a=b;
            b=t;
        }
        return a;
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> mp;
        for(int k: deck) mp[k]++;
        bool flag=true;
        if(deck.size()==1) return false;
        int t=mp[deck[0]];
        for(auto m :mp){
            t=gcdfun(t,m.second);
        }
        return t>1;
    }
};