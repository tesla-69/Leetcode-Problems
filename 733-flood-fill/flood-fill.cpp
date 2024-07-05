class Solution {
public:
 void dfs(int i, int j, vector<vector<int>>& image, vector<vector<int>>& vis
    , vector<vector<int>>& copy, int color, int newColor, int n, int m){
        vis[i][j] = 1;
        copy[i][j] = newColor;
        for(int a=-1;a<=1;a++){
            for(int b=-1;b<=1;b++){
                if(abs(a) == 1 && abs(b) == 1) continue;
                int nsr = i + a;
                int nsc = j + b;
                if(nsr>=0 && nsr < n && nsc>=0 && nsc<m &&
                image[nsr][nsc] == color && !vis[nsr][nsc]){
                    dfs(nsr,nsc,image,vis,copy,color,newColor,n,m);
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int> > copy(n,vector<int>(m,0));
        vector<vector<int> > vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                copy[i][j] = image[i][j];
            }
        }
        int oldcolor = image[sr][sc];
        
        dfs(sr,sc,image,vis,copy,oldcolor,color,n,m);
        
        return copy;
    }
};