class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& events,
              vector<vector<int>>& dp, int& k) {
        if (j == k)
            return 0;
        if (i == events.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int take = 0;
        // cout << i << " " << prevend << endl;
        take += events[i][2];
        int s = i + 1;
        int ind = events.size();
        int e = events.size();
        while(s < e) {
            int mid = s + (e - s) / 2;
            if(events[mid][0] > events[i][1]) {
                ind = mid;
                e = mid;
            }
            else s = mid + 1;
        }
        take += solve(ind, j + 1, events, dp, k);
    
        int ntake = solve(i + 1, j, events, dp, k);

        return dp[i][j] = max(take, ntake);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return solve(0, 0, events, dp, k);
    }
};