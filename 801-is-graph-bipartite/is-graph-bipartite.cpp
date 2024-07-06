class Solution {
public:

    bool dfs(int i ,int parent, int color[] , vector<vector<int>>& graph){
        if(parent == -1) {
            color[i] = 0;
        }
        else {
            color[i] = !color[parent];
        }
        for(auto it:graph[i]) {
            if(color[it] == -1) {
                if(dfs(it,i,color,graph) == false) return false;
            }
            else if(color[it] == color[i]) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        int color[V];
        for(int i=0;i<V;i++){
            color[i] = -1;
        }
        for(int i=0;i<V;i++){
            if(color[i] == -1) {
                if(dfs(i,-1,color,graph) == false) return false;
            }
        }
        return true;
    }
};