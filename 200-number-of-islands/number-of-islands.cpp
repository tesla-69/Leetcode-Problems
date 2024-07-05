class Solution {
public:

    void bfs(vector<vector<char> > &grid , vector<vector<int> > &vis
    , int row , int col , int n , int m){
        vis[row][col] = 1;
        queue<pair<int , int>> q;
        q.push({row,col});
        
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(int a = -1;a<=1;a++){
                for(int b= -1;b<=1;b++){
                    if(abs(a) == 1 && abs(b) == 1) continue;
                    int nrow = i + a;
                    int ncol = j + b;
                    if(nrow>=0 && nrow<n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                        q.push({nrow,ncol});
                        vis[nrow][ncol] = 1;
                    }
                }
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
         int n = grid.size();
        int m = grid[0].size();
        vector<vector<int> > vis(n , vector<int>(m , 0));
        
        int cnt = 0;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && !vis[i][j]) {
                    bfs(grid , vis, i , j, n , m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};