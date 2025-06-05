class Solution {
public:
    
    int solve(vector<vector<int>>& grid, int n, int m1, int m2, vector<vector<vector<int>>> &dp) {
        if(m1 < 0 || m1 >= grid[0].size() || m2 < 0 || m2 >= grid[0].size()) return 0;
        if(n == grid.size() - 1) {
            if(m1 == m2) return grid[n][m1];
            else return grid[n][m1] + grid[n][m2];
        }

        if(dp[n][m1][m2] != -1) return dp[n][m1][m2];

        int a = solve(grid, n+1, m1-1, m2-1, dp);
        int b = solve(grid, n+1, m1-1, m2, dp);
        int c = solve(grid, n+1, m1-1, m2+1, dp);
        int d = solve(grid, n+1, m1, m2-1, dp);
        int e = solve(grid, n+1, m1, m2, dp);
        int f = solve(grid, n+1, m1, m2+1, dp);
        int g = solve(grid, n+1, m1+1, m2-1, dp);
        int h = solve(grid, n+1, m1+1, m2, dp);
        int i = solve(grid, n+1, m1+1, m2+1, dp);

        if(m1 == m2) {
            return dp[n][m1][m2] = max({a,b,c,d,e,f,g,h,i}) + grid[n][m1];
        }
        else return dp[n][m1][m2] = max({a,b,c,d,e,f,g,h,i}) + grid[n][m1] + grid[n][m2];
    } 


    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

        return solve(grid, 0, 0, m-1, dp);

    }
};