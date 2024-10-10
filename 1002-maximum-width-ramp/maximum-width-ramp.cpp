class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxele(n);
        maxele[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            maxele[i] = max(maxele[i + 1], nums[i]);
        }
        int l=0, r=0, maxw=0;
        while(r<n){
            while(nums[l]>maxele[r] && l<r){
                l++;
            }
            maxw=max(maxw, r-l);
            r++;

        }

        return maxw;
    }
};