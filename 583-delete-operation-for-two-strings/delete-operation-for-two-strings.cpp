class Solution {
public:
    int lcs(string s1, string s2, int n, int m) {
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < m + 1; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
    int minDistance(string words1, string words2) {
        int n = words1.size();
        int m = words2.size();
        return m - 2*lcs(words1, words2, n, m) + n; 
    }
};