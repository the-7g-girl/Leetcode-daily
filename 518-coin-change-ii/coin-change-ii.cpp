class Solution {
public:
    int f(int i, int amt, vector<int>& coins, vector<vector<int>>& dp) {
        if (amt == 0)
            return 1;
        if (i == 0)
            return 0;
        if (dp[i][amt] != -1)
            return dp[i][amt];
        dp[i][amt] = f(i - 1, amt, coins, dp);
        if (amt >= coins[i - 1]) {
            dp[i][amt - coins[i - 1]] = f(i, amt - coins[i - 1], coins, dp);
            dp[i][amt]+=dp[i][amt - coins[i - 1]];
        }
        return dp[i][amt];
    }
    int change(int sum, vector<int>& coins) {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        dp[n][sum]=f( n,  sum,  coins, dp);
        return dp[n][sum];
    }
};
