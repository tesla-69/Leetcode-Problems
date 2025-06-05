class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& vec) {
        int n = vec.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ans = INT_MAX;
        // for(int i = 0; i < n; i++) {
        //     int temp = solve(vec, 0, i, dp);
        //     ans = min(ans, temp);
        // }
        // return ans;

        for (int i = 0; i < n; i++) {
            dp[n - 1][i] = vec[n - 1][i];
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int d = dp[i + 1][j];
                int dr = INT_MAX, dl = INT_MAX;
                if (j < n - 1)
                    dr = dp[i + 1][j + 1];
                if (j > 0)
                    dl = dp[i + 1][j - 1];

                dp[i][j] = min({d, dr, dl}) + vec[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[0][i]);
        }
        return ans;
    }
};