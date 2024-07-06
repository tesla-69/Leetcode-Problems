class Solution {
public:
    void solve(vector<vector<char>>& board) {
         queue<pair<int,int>> q;
         int n = board.size();
         int m = board[0].size();
        vector<vector<int> > vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i == n-1 || j==0 || j==m-1){
                    if(board[i][j] == 'O'){
                        q.push({i,j});
                        vis[i][j] = 1;
                    }
                }
            }
        }
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            
            q.pop();
            
            for(int a=-1;a<=1;a++){
                for(int b=-1;b<=1;b++){
                    if(abs(a) == 1 && abs(b) == 1) continue;
                    
                    int nr = r + a;
                    int nc = c + b;
                    if(nr>=0 && nr<n && nc>=0 &&nc<m 
                    && !vis[nr][nc] && board[nr][nc] == 'O'){
                        vis[nr][nc] =1;
                        q.push({nr,nc});
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
        // return mat;
    }
};