class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        map<vector<int>, int> mp;
        int cnt = 0;
        for(auto it: grid) {
            mp[it]++;
        }
        for(int i = 0; i < m; i++) {
            vector<int> t;
            for(int j = 0; j < n; j++) {
                t.push_back(grid[j][i]);
            }
            cnt += mp[t];
        }
        return cnt;
    }
};