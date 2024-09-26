class Solution {
public:
    int find(int i, int sum, vector<int>& nums, vector<vector<int>>& dp) {
        if (sum == 0)
            return 1;
        if (i == 0)
            return 0;
        if (dp[i][sum] != -1)
            return dp[i][sum];
        dp[i][sum] = find(i - 1, sum, nums, dp);  
        if (sum >= nums[i - 1]) 
            dp[i][sum] += find(i - 1, sum - nums[i - 1], nums, dp);  
        return dp[i][sum];
    }

    int findTargetSumWays(vector<int>& nums, int diff) {
        int tot = 0, cnt=0;
        if(nums.size()==1) {
            if(diff==nums[0] || diff+nums[0]==0) return 1;
            else return 0;
        }
        sort(nums.begin(),nums.end());
        for (int ele : nums) {
            if(ele==0) cnt++;
            tot += ele;
        }
        int n = nums.size();
        if ((tot + diff) % 2 != 0)
            return 0;
        int s = (tot + diff) / 2;
        if(s<0) s=(tot-diff)/2;
        vector<vector<int>> dp(n + 1, vector<int>(s + 1, -1));
        int ans=find(n, s, nums, dp);
        if(ans==-1) return 0;
        ans=ans*pow(2,cnt);       
        return ans;
    }
};
