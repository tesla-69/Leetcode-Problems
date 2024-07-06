class Solution {
public:

    void dfs(int r , int c , vector<vector<int>>& grid , vector<vector<int>>& vis,int n ,int m){
        vis[r][c] = 1;
        for(int a =-1;a<=1;a++){
            for(int b=-1;b<=1;b++){
                if(abs(a) == 1 && abs(b) == 1) continue;
                int nr = r +a;
                int nc = c + b;
                if(nr>=0 && nr<n && nc>=0 && nc<m &&
                !vis[nr][nc] && grid[nr][nc] ==1){
                    dfs(nr,nc,grid,vis,n,m);
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int> > vis(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(grid[i][j] == 1){
                       dfs(i,j,grid,vis,n,m);
                    }
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] ==1) cnt++;
            }
        }
        return cnt;
    }
};