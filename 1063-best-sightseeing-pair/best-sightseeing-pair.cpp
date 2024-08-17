class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& a) {
        int ans=0, mx=0;
        for(int i=0;i<a.size();i++){
            ans=max(ans,mx+(a[i]-i));
            mx=max(mx, a[i]+i);
        }
        return ans;
    }
};