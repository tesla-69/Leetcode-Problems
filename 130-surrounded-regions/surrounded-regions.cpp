class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i = 0;i < n ; i++) {
            for(int j =0 ; j<m ; j++){
                if(i==0 || i == n-1 || j == 0 || j == m-1) {
                    if(board[i][j] == 'O') {
                        q.push({i,j});
                        vis[i][j] = 1;
                    }
                }
            }
        }
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i =-1; i<=1 ; i++) {
                for(int j =-1; j<= 1 ; j++) {
                    if(abs(i) == abs(j)) continue;
                    int nr = r+i;
                    int nc = c+j;
                    if(nr>=0 && nr < n && nc >= 0 && nc < m 
                    && !vis[nr][nc] && board[nr][nc] == 'O'){
                        q.push({nr,nc});
                        vis[nr][nc] = 1;
                    }
                }
            }
        }
        for(int i = 0; i< n ; i++ ) {
            for(int j=0; j<m;j++) {
                if(board[i][j] == 'O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};