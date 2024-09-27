class Solution {
public:
    bool canPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int tot=0;
        for(int i: nums){
            tot+=i;
        }
        if(tot%2!=0) return false;
        tot=tot/2;
        int n=nums.size();
        vector<vector<bool>> dp(n+1, vector<bool> (tot+1,false));
        for(int i=0; i<n+1 ; i++){
            dp[i][0]=true;
        }
        for(int i=1; i<n+1; i++){
            for(int j=1; j<tot+1; j++){
                if(j>=nums[i-1])
                dp[i][j]=dp[i-1][j] || dp[i-1][j-nums[i-1]] ;
                else 
                dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][tot];
    }
};