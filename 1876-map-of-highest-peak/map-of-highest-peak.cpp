class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int> , int>> q;
        // vector<vector<int>> ans ()
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i =0 ; i < n ; i++) {
            for(int j =0; j< m; j++) {
                if(isWater[i][j] == 1) {
                    vis[i][j] = 1;
                    q.push({{i,j},0});
                }
            }
        }
        while(!q.empty()) 
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int val = q.front().second;
            q.pop();
            ans[r][c] = val;
            for(int i = -1; i<=1 ; i++) {
                for(int j =-1; j<=1; j++) {
                    if(abs(i) == abs(j)) continue;
                    int nr = r + i;
                    int nc = c + j;
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m 
                    && !vis[nr][nc] && !isWater[nr][nc]) {
                        vis[nr][nc] = 1;
                        q.push({{nr,nc} , val+1});
                    }
                }
            }
        }
        return ans;
    }
};