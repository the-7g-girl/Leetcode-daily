class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
        vector<int> dp(amt + 1, INT_MAX );
        dp[0] = 0;
        for (int i = 1; i < amt + 1; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i >= coins[j] && dp[i - coins[j]] != INT_MAX)
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
        if (dp[amt] == INT_MAX)
            return -1;
        return dp[amt];
    }
};