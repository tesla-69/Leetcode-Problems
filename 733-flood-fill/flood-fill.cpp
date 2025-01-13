class Solution {
private:
    void dfs(vector<vector<int>>& image,vector<vector<int>>& copy, vector<vector<int>>& vis, int r, int c, int n, int m, int color, int presentcolor) {
        vis[r][c] = 1;
        copy[r][c] = color;
        for(int i = -1 ; i <= 1; i++){
            for(int j =-1 ; j <= 1; j++){
                if(abs(i) == abs(j)) continue;
                int nr = r + i;
                int nc = c + j;
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && image[nr][nc] == presentcolor){
                    dfs(image , copy,vis,nr,nc,n,m,color,presentcolor);
                }
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> copy = image;
        int presentcolor = image[sr][sc];
        vector<vector<int>> vis(n, vector<int>(m, 0));
        dfs(image,copy, vis, sr, sc, n, m, color, presentcolor);
        return copy;
    }
};