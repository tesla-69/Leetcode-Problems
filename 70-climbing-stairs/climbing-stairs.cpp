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
        int prev1 = 1, prev2 = 1;
        // dp[0] = 1, dp[1] = 1;
        int curr = 1;
        for(int i = 2; i <= n; i++) {
            // dp[i] = dp[i-1] + dp[i-2];
            curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }
        // return dp[n];
        return curr;
    }
};