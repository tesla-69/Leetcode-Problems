class Solution {
    void dfs(vector<vector<int>>& grid, int r, int c, int node,
             vector<vector<int>>& vis, int& val, int n, int m) {
        vis[r][c] = 1;
        if (grid[r][c] < node) {
            val++;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (abs(i) == 1 && abs(j) == 1)
                        continue;
                    int nr = r + i;
                    int nc = c + j;
                    if (nr >= 0 && nc >= 0 && nc < m && nr < n &&
                        !vis[nr][nc]) {
                        dfs(grid, nr, nc, node, vis, val, n, m);
                    }
                }
            }
        }
    }

public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size();
        int m = grid[0].size();

        int qs = queries.size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < qs; i++) {
            arr.push_back({queries[i], i});
        }
        sort(arr.begin(), arr.end());
        priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>> , 
        greater<pair<int,pair<int, int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        
        vector<vector<int>> vis(n, vector<int>(m, 0));

        vector<int> ans(qs);
        for (int i = 0; i < qs; i++) {
            int cnt = 0;
            cout<<"q size : "<<pq.size()<<endl;
            while (!pq.empty()) {
                auto it = pq.top();
                int val = it.first;
                int r = it.second.first;
                int c = it.second.second;
                if(vis[r][c]) {
                    pq.pop();
                    continue;
                }
                cout<<"r = "<<r<<" c = "<<c<<endl;
                if (val < arr[i].first) {
                    pq.pop();
                    cnt++;
                    vis[r][c] = 1;
                    for (int i = -1; i <= 1; i++) {
                        for (int j = -1; j <= 1; j++) {
                            if (abs(i) == 1 && abs(j) == 1)
                                continue;
                            int nr = r + i;
                            int nc = c + j;
                            if (nr >= 0 && nc >= 0 && nc < m && nr < n && !vis[nr][nc]) {
                                pq.push({grid[nr][nc],{nr,nc}});
                            }
                        }
                    }
                }
                else{
                    cout<<"break"<<endl;
                    break;
                } 
            }
            if(i == 0) ans[arr[i].second] = cnt;
            else{
                cout<<"ans "<<ans[arr[i-1].second] << "cnt: " <<cnt<<endl;
                ans[arr[i].second] = ans[arr[i-1].second] + cnt;
            }
            cout<<endl;
        }

        return ans;
        // for(int i = 0; i< q; i++) {
        //     vector<vector<int>> vis(n, vector<int>(m, 0));
        //     int val = 0;
        //     dfs(grid, 0, 0, queries[i], vis, val, n, m);
        //     ans.push_back(val);
        // }
    }
};