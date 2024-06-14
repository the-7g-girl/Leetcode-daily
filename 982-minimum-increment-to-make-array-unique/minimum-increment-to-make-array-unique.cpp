class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        if(n==0 || n==1) return 0;
        for(int i=1;i<n;i++){
            while(nums[i]<=nums[i-1]) {ans++; nums[i]++;}
        }
        return ans;
    }
};