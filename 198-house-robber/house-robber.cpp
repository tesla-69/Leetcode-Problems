class Solution {
    int solve(int n, vector<int>&nums, vector<int> &dp) {
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        int take = nums[n] + solve(n-2, nums, dp);
        int ntake = solve(n-1, nums, dp);
        return dp[n] = max(take, ntake);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);
        dp[0] = nums[0];
        // return solve(n-1, nums, dp);
        for(int i = 1; i<n; i++) {
            int take = nums[i];
            if(i-2 >=0) take += dp[i-2];
            int ntake = dp[i-1];
            dp[i] = max(take, ntake);
        }
        return dp[n-1];
    }
};