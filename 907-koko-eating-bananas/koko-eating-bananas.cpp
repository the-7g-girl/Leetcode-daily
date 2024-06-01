class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo=1,hi=0,i=0,mid;
        while(i<piles.size()){
            hi=max(hi,piles[i]);
            i++;
        }
        while(hi>lo){
            mid=(hi+lo)/2;
            if(!possible(piles,mid,h)) lo=mid+1;
            else hi=mid;
        }
    return lo;
    }

    bool possible(vector<int>& piles,int k, int h){
        int ans=0;
        for(int i=0;i<piles.size();i++){
            ans+=ceil(piles[i]*1.00/k);
        }
        if(ans<=h) return true;
        return false;
    }
};