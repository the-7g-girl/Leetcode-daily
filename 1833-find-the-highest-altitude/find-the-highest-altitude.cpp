class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ht=0;
        int ans=0;
        for(int i: gain){
            ht+=i;
            ans=max(ans,ht);
        }
        return ans;
    }
};