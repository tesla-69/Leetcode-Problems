class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n, 0);
        vis[0] = 1;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto it: rooms[0]) pq.push(it);
        while(!pq.empty()) {
            int key = pq.top();
            pq.pop();
            vis[key] = 1;
            for(auto it : rooms[key]) {
                if(!vis[it]) pq.push(it);
            }
        }
        for(auto it: vis) if(it == 0) return false;
        return true;
    }
};