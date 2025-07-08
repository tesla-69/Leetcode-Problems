class Solution {
public:
    int minReorder(int n, vector<vector<int>>& arr) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : arr) {
            adj[it[0]].push_back({it[1], 1});
            adj[it[1]].push_back({it[0], 0});
        }
        // for(int i = 0; i < n; i++) {
        //     // cout<<i<<" ";
        //     for(auto it: adj[i]) cout<<it.first<< " ";
        //     // cout<<endl;
        // }
        vector<int> vis(n, 0);
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        int cnt = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            // cout<<node<<"    ";
            vis[node] = 1;
            for(auto it: adj[node]) {
                // cout<<it.first<<" "<<it.second<<endl;
                if(!vis[it.first]){
                    if(it.second == 1) cnt++;
                    q.push(it.first);
                } 
            }
        }
        return cnt;
    }
};