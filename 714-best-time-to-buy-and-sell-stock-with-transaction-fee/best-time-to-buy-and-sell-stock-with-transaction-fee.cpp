class Solution {
public:
    int solve(int i, int canBuy, int fee, vector<int>& prices, vector<vector<int>>& dp) {
        if (i == prices.size()) return 0;

        if (dp[i][canBuy] != -1) return dp[i][canBuy];

        if (canBuy) {
            int buy = -prices[i] + solve(i + 1, 0, fee, prices, dp);
            int skip = solve(i + 1, 1, fee, prices, dp);
            return dp[i][canBuy] = max(buy, skip);
        } else {
            int sell = prices[i] - fee + solve(i + 1, 1, fee, prices, dp);
            int skip = solve(i + 1, 0, fee, prices, dp);
            return dp[i][canBuy] = max(sell, skip);
        }
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, fee, prices, dp);
    }
};
