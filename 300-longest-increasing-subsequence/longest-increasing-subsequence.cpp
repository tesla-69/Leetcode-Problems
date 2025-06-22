class Solution {
public:

    int solve(int i, int pi, vector<int>& nums, vector<vector<int>> &dp) {
        if(i >= nums.size()) return 0;
        if(dp[i][pi+1] != -1) return dp[i][pi+1];

        int len = solve(i+1, pi, nums, dp);
        // int take = INT_MIN;  
        if(pi == -1 || nums[pi] < nums[i]) {
            len = max(len, 1 + solve(i+1, i, nums, dp));
        }
        return dp[i][pi+1] = len;
        
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(0, -1, nums, dp);
    }
};