class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // dp[i][j] = LIS starting at index i, with previous index j-1 (j shifted by +1)
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i = n - 1; i >= 0; i--) {
            for(int j = n; j >= 0; j--) {
                int len = dp[i+1][j]; // skip nums[i]
                if(j == n || nums[i] > nums[j]) {
                    len = max(len, 1 + dp[i+1][i]);
                }
                dp[i][j] = len;
            }
        }

        return dp[0][n]; // start from i=0 with previous index = -1 (mapped to n)
    }
};
// 