class Solution {
public:
    void topo(vector<int> adj[], stack<int>& s, vector<int>& vis, int k) {
        vis[k] = 1;
        for (auto it : adj[k]) {
            if (!vis[it])
                topo(adj, s, vis, it);
        }
        s.push(k);
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }
        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it : adj[i]) {
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0 ; i<numCourses ; i++){
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        if(topo.size() == numCourses) return true;
        else return false;
    }
};