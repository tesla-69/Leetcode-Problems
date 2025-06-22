class Solution {
public:

    int solve(int i, int canbuy, vector<int>& prices, vector<vector<int>>& dp) {
        if(i >= prices.size()) return 0;
        if(dp[i][canbuy] != -1) return dp[i][canbuy];
        if(canbuy) {
            int buy = -prices[i] + solve(i + 1, 0, prices, dp);
            int nbuy = solve(i + 1, 1, prices, dp);
            return dp[i][canbuy] = max(buy, nbuy);
        }
        else {
            int sell = prices[i] + solve(i + 2, 1, prices, dp);
            int nsell = solve(i+1, 0, prices, dp);
            return dp[i][canbuy] = max(sell, nsell);
        }

    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2, -1));
        return solve(0, 1, prices, dp);      
    }
};