class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int lo=1,hi=n,mid;
        if(target<=nums[0]) return 0;
        if(target>nums[n-1]) return n;
        
        if(n==1) {if(nums[0]<=target) return 0; return 1;}
        while(hi>=lo){
            mid=(hi+lo)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) hi=mid-1;
            else lo=mid+1;
        }
        return lo;
    }
};