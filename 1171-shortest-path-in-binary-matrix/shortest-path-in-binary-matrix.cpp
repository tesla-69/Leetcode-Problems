class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        pair<int, int> source = {0,0};
        pair<int, int> destination = {n-1,n-1};
        if(grid[0][0] == 1) return -1;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>
        ,greater<pair<int,pair<int,int>>>> pq;
        dist[source.first][source.second] = 0;
        pq.push({0,{source.first,source.second}});
        while(!pq.empty()) {
            auto it = pq.top();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            pq.pop();
            for(int i =-1; i<=1; i++) {
                for(int j= -1; j<=1 ; j++) {
                    // if(abs(i) == 1 && abs(j) == 1) continue;
                    int nr = r + i;
                    int nc = c + j;
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 0) {
                        if(dist[nr][nc] > dis + 1) {
                            dist[nr][nc] = dis + 1;
                            pq.push({dis + 1, {nr,nc}});
                        }
                    }
                }
            }
        }
        if(dist[destination.first][destination.second] == 1e9) return -1;
        else return dist[destination.first][destination.second]+1;
    }
};