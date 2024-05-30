class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        if(nums[1]<nums[0]) return 0;
        if (n == 2) return nums[0] > nums[1] ? 0 : 1;
        if(nums[n-2]<nums[n-1]) return n-1;
        int lo=0,hi=nums.size()-1;
        int mid;
        while(hi>lo){
            mid=(hi+lo)/2;
            if(mid!=0){
            if(nums[mid]<nums[mid+1] && nums[mid]>nums[mid-1]) lo=mid+1;
            else if(nums[mid]>nums[mid+1] && nums[mid]<nums[mid-1]) hi=mid-1;
            else if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]) return mid;
            else lo=mid;
            }
            if(mid==0) return mid+1;                
        }
        return hi;
    }
};