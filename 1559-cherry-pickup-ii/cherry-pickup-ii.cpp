class Solution {
public:
    
    int solve(vector<vector<int>>& grid, int n, int m1, int m2, vector<vector<vector<int>>> &dp) {
        if(m1 < 0 || m1 >= grid[0].size() || m2 < 0 || m2 >= grid[0].size()) return 0;
        if(n == grid.size() - 1) {
            if(m1 == m2) return grid[n][m1];
            else return grid[n][m1] + grid[n][m2];
        }

        if(dp[n][m1][m2] != -1) return dp[n][m1][m2];
        int temp = 0;
        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                temp = max(temp, solve(grid, n+1, m1+i, m2+j, dp));
            }
        }
        int ans = temp + grid[n][m1];
        return m1 == m2 ? dp[n][m1][m2] = ans :  dp[n][m1][m2] = ans + grid[n][m2];        
    } 


    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

        return solve(grid, 0, 0, m-1, dp);

    }
};