class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, INT_MAX));

        // Base Case
        for (int j = 0; j <= amount; j++) {
            if (j % coins[0] == 0) 
                dp[0][j] = j / coins[0];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= amount; j++) {
                int nt = dp[i-1][j];
                int t = INT_MAX;
                if (coins[i] <= j && dp[i][j - coins[i]] != INT_MAX) 
                    t = 1 + dp[i][j - coins[i]];
                dp[i][j] = min(t, nt);
            }
        }

        return dp[n-1][amount] == INT_MAX ? -1 : dp[n-1][amount];
    }
};



