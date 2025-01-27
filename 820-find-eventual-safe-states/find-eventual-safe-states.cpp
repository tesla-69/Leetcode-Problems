class Solution {
private:
    bool dfs(vector<vector<int>>& graph, int node, vector<int>& vis,
             vector<int>& pathvis, vector<int>& check) {
        vis[node] = 1;
        pathvis[node] = 1;
        check[node] = 0;
        for (auto it : graph[node]) {
            if (!vis[it]) {
                if (dfs(graph, it, vis, pathvis, check) == true) {
                    check[node] = 0;
                    return true;
                }
            } else if (pathvis[it]) {
                return true;
            }
        }
        check[node] = 1;
        pathvis[node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> check(n, 0);
        vector<int> pathvis(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(graph, i, vis, pathvis, check);
            }
        }
        vector<int> ans;
        for (int it = 0; it < n; it++)
            if (check[it] == 1)
                ans.push_back(it);
        return ans;
    }
};