class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        while (!pq.empty()) {
            auto it = pq.top();
            int effort = it.first;
            int r = it.second.first;
            int c = it.second.second;
            pq.pop();
            if (r == n - 1 && c == m - 1)
                return effort;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (abs(i) == 1 && abs(j) == 1)
                        continue;
                    int nr = r + i;
                    int nc = c + j;
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                        int newEffort =
                            max(abs(heights[nr][nc] - heights[r][c]), effort);
                        if (newEffort < dist[nr][nc]) {
                            dist[nr][nc] = newEffort;
                            pq.push({newEffort, {nr, nc}});
                        }
                    }
                }
            }
        }
        return 0;
    }
};