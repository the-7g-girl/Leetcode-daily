class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int lo=0,hi=n-1,mid;
        if(n==0 ) return {-1,-1};
        if(n==1){
            if(nums[0]==target) return {0,0};
            else return {-1,-1};
        }
        int k;
        if(nums[0]==target){ k=0; while(nums[k]==target) {k++; if(k==n) break;} return {0,k-1}; }
        if(nums[n-1]==target) { k=n-1; while(nums[k]==target) {k--; if(k==-1) break;} return {k+1,n-1};}
        while(lo<hi){
            mid=(lo+hi)/2;
            if(nums[mid]<target) lo=mid+1;
            else hi=mid;
        }
        if(nums[lo]==target) {
            k=lo,hi=lo;
            while(nums[k]==target) {k--; if(k==-1) break;} 
            while(nums[hi]==target) {hi++; if(hi==n) break;} 
            return {k+1,hi-1};
        }
        if(nums[hi]==target) {
            lo=hi,k=hi;
            while(nums[lo]==target) {lo--; if(lo==-1) break;} 
            while(nums[k]==target) {k++; if(k==n) break;} 
            return {lo+1,k-1};
        }
        return {-1,-1};
    }
};