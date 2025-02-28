class Solution {
public:
    void solve(string x, string y, int m, int n, string& ans) {
        int dp[m + 1][n + 1];
        for (int i = 0; i < m + 1; i++) {
            for (int j = 0; j < n + 1; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (x[i - 1] == y[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        int i = m;
        int j = n;
        while (i > 0 && j > 0) {
            if (x[i - 1] == y[j - 1]) {
                ans += x[i-1];
                i--;
                j--;
            } else {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    ans += x[i - 1];
                    i--;
                } else {
                    ans += y[j - 1];
                    j--;
                }
            }
        }
        while (i > 0) {
            ans += x[i - 1];
            i--;
        }
        while (j > 0) {
            ans += y[j - 1];
            j--;
        }
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        string ans = "";
        solve(str1, str2, m, n, ans);
        reverse(ans.begin() , ans.end());
        return ans;
    }
};