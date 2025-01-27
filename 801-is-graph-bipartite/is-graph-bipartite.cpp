class Solution {
private: 
    bool dfs(vector<vector<int>> &graph , vector<int> &color , int node, int col) {
        // if(color[node] == -1)
            color[node] = col;
        for(auto it : graph[node]) {
            if(color[it] == col) return false;
            else if(color[it] == -1) 
                if(dfs(graph,color,it,!col) == false) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0; i<n; i++){
            if(color[i] == -1) {
                if(dfs(graph,color,i,0) == false) return false;
            }
        }
        return true;
    }
};