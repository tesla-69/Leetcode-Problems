class Solution {
    int solve(int n, int s, vector<int>&nums, vector<int> &dp) {
        if(n < s) return 0;
        if(dp[n] != -1) return dp[n];
        int take = nums[n] + solve(n-2, s, nums, dp);
        int ntake = solve(n-1, s, nums, dp);
        return dp[n] = max(take, ntake);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp(n+1, -1), dp2(n+1,-1);
        return max(solve(n-1, 1, nums, dp) , solve(n-2, 0, nums, dp2));
    }
};