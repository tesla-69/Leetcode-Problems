class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i= 0; i<n ; i++) {
            for(int j=0; j < m ; j++) {
                if(i==0 || j==0 || i == n-1 || j == m-1){
                    if(grid[i][j] == 1) {
                        vis[i][j] = 1;
                        q.push({i,j});
                    }
                }
            }
        }
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i =-1 ;i <= 1; i++){
                for(int j =-1 ; j <=1; j++){
                    if(abs(i) == abs(j)) continue;
                    int nr = r+i;
                    int nc = c+j;
                    if(nr>=0 && nc>=0 && nr < n && nc<m && !vis[nr][nc] && grid[nr][nc] == 1){
                        q.push({nr,nc});
                        vis[nr][nc] = 1;
                    }
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i< n; i++) {
            for(int j=0; j < m ; j++) {
                cout<<vis[i][j]<<" ";
                if(!vis[i][j] && grid[i][j]) cnt++;
            }
            cout<<endl;
        }
        return cnt;
    }
};