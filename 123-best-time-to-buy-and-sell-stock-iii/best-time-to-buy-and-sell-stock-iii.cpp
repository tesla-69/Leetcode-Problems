class Solution {
public:
    int solve(int i, int buy, int left, vector<int>& arr, vector<vector<vector<int>>> &dp) {
        if(left == 0) return 0;
        if(i >= arr.size()) return 0;
        if(dp[i][buy][left] != -1) return dp[i][buy][left];
        if(buy) {
            int take = -arr[i] + solve(i+1, 0, left, arr, dp);
            int ntake = solve(i+1, 1, left, arr, dp);
            return dp[i][buy][left] = max(take, ntake);
        }
        else {
            int sell = arr[i] + solve(i+1, 1, left - 1, arr, dp);
            int nsell = solve(i + 1, 0, left, arr, dp);
            return dp[i][buy][left] = max(sell, nsell);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3,-1)));
        return solve(0, 1, 2, prices, dp);
    }
};