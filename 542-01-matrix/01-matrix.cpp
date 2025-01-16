class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<pair<int,int> , int > > q;
        vector<vector<int>> ans(n , vector<int>(m,0));
        vector<vector<int>> vis(n , vector<int>(m,0));
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(mat[i][j] == 0) {
                    vis[i][j] = 1;
                    // ans[i][j] = 0;
                    q.push({{i,j} , 0});
                }
            }
        }
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            // if(!vis[r][c])
            ans[r][c] = dis;
            for(int i =-1; i<=1; i++){
                for(int j =-1;j<=1;j++){
                    if(abs(i) == abs(j)) continue;
                    int nr = r + i;
                    int nc = c + j;
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && 
                        !vis[nr][nc]){
                            vis[nr][nc] = 1;
                            q.push({{nr,nc},dis+1});
                        }
                }
            }
        }
        return ans;
    }
};