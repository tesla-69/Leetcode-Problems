class RecentCounter {
public:
    vector<int>arr;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        arr.push_back(t);
        int tar = t - 3000;
        int cnt = 1;
        for(int i = arr.size() - 2; i >= 0; i--) {
            if(arr[i]>=t-3000) cnt++;
        }
        
        return cnt;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */