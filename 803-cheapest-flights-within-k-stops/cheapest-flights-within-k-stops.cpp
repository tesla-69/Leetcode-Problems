class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,pair<int,int>>> pq;
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0; i<flights.size(); i++) {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        vector<int> dist(n,1e9);
        pq.push({0, {src,0}});
        dist[src] = 0;
        while(!pq.empty()) {
            auto it = pq.front();
            int stops = it.first;
            int station = it.second.first;
            int cost = it.second.second;
            pq.pop();
            if(stops > k) continue;
            for(auto it : adj[station]) {
                int nextStation = it.first;
                int price = it.second;
                int newCost = price + cost;
                if(newCost < dist[nextStation] && stops<=k) {
                    dist[nextStation] = newCost;
                    pq.push({stops+1,{nextStation, newCost}});
                }
            }
        }
        if(dist[dst] == 1e9)
        return -1;
        else return dist[dst];
    }
};