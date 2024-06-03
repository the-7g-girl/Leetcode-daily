class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = *max_element(weights.begin(), weights.end()); // Initialize lo as the maximum weight
        int hi = accumulate(weights.begin(), weights.end(), 0); // Initialize hi as the sum of all weights
        int mid;
        while(hi>lo){
            mid=(hi+lo)/2;
            if(!possible(weights,mid,days)) lo=mid+1;
            else hi=mid;
        }
        return lo;
    }
    bool possible(vector<int>& piles,int k, int h){
        int ans=0,curr=0;
        for(int i=0;i<piles.size();i++){
            if(piles[i]>k) return false;
            else if(curr+piles[i]<k) curr+=piles[i];
            else if(curr+piles[i]==k) { ans++; curr=0; }
            else if(curr+piles[i]>k) { ans++; curr=piles[i]; }
        }
        if(curr!=0) ans++;
        if(ans<=h) return true;
        return false;
    }
};