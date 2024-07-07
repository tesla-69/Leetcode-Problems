class Solution {
public:

      bool dfs(int node,  vector<int>& vis ,  vector<int>& pathvis,vector<vector<int>>& graph,  vector<int>& safe){
        vis[node] = 1;
        pathvis[node] = 1;
        safe[node] = 0;
        for(auto it: graph[node]) {
            if(!vis[it]) {
                if(dfs(it,vis,pathvis,graph,safe)==true) {
                    safe[node] = 0;
                    return true;     
                }
            }
            else if(pathvis[it]) {
                safe[node] = 0;
                return true;
            }
        }
        safe[node] = 1;
        pathvis[node] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> pathvis(n, 0);
        vector<int> safe(n, 0);
        vector<int> ans;
        for(int i =0 ;i <n;i++){
            if(!vis[i]){
                dfs(i,vis,pathvis,graph,safe);
            }
        }
        for(int i=0 ; i<n;i++ ) {
            if(safe[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};