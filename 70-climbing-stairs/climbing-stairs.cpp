class Solution {
    int noOfWays(int n, vector<int>&arr) {
        if(n == 1) return arr[n] = 1;
        if(arr[n] != -1) return arr[n]; 
        int l = noOfWays(n-1, arr);
        int r = noOfWays(n-2, arr);
        return arr[n] = l+r;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1, dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};