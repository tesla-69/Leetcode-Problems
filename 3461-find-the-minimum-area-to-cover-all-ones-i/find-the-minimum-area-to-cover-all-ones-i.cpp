class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> row(n, 0), col(m, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j]) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        int rcnt = 0, ccnt = 0;

        for(int i = 0; i < n; i++) {
            if(row[i] == 0) rcnt++;
            else break;
        }
        for(int i = n-1; i >= 0; i--) {
            if(row[i]) break;
            else rcnt++;
        }
        for(int i = 0; i < m; i++) {
            if(col[i] == 0) ccnt++;
            else break;
        }
        for(int i = m-1; i >= 0; i--) {
            if(col[i]) break;
            else ccnt++;
        }

        int r = n - rcnt;
        int c = m - ccnt;

        return r * c;
    }
};