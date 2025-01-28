class Solution {
private:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i,int j, int& curr,
             int& ans) {
                 int n = grid.size();
        int m = grid[0].size();
        vis[i][j] = 1;
        curr += grid[i][j];
        
        
        for(int r =-1 ; r<=1;r++) {
            for(int c = -1;c<=1;c++) {
                if(abs(r) == abs(c)) continue;
                int nr = r+i;
                int nc = c+j;
                if(nr>=0&&nr<n && nc<m && nc>=0 && !vis[nr][nc] && grid[nr][nc] > 0) {
                    dfs(grid,vis,nr,nc,curr,ans);
                }
            }
        }
        // curr -= grid[i][j];
        // vis[i][j] = 0;
    }

public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        int cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // if(grid[i][j] == 0) cnt++;
                if (!vis[i][j] && grid[i][j] != 0) {
        int curr = 0;
                    dfs(grid, vis, i,j, curr, ans);
                    ans = max(ans,curr);

                }
            }
        }
        // if(cnt == 0) dfs(grid,vis,0,0,curr,ans);
        return ans;
    }
};