class Solution {
private: 
    void dfs(vector<vector<char>> &grid , vector<vector<int>> &vis, int r , int c, int n , int m){
        vis[r][c] = 1;
        for(int i = -1 ; i <= 1 ; i++){
            for(int j = -1;j<=1;j++) {
                if(abs(i) == abs(j)) continue;
                int nr = r + i;
                int nc = c + j;
                if(nr >= 0 && nr<n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == '1'){
                    dfs(grid,vis,nr,nc,n,m);
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j =0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1') {
                    dfs(grid,vis,i,j,n,m);
                    cout<<i<<" "<<j<<endl;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};