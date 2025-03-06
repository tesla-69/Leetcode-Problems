class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = n*n;
        vector<int> flag(m,0);
        for(int i =0; i<n; i++) {
            for(int j =0; j<n; j++) {
                int val = grid[i][j] - 1;
                flag[val]++;
            }
        }
        vector<int> ans(2);
        for(int i = 0;i < n*n; i++) {
            if(flag[i] == 0) ans[1] = i+1;
            else if(flag[i] == 2) ans[0] = i+1;
        }
        return ans;
    }
};