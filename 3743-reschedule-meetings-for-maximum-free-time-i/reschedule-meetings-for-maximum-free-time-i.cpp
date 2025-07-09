class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<pair<int,int>> free;
        int s = 0 ;
        int e = 0;
        for(int i = 0;i<n;i++) {
            if( s < startTime[i]) {
                free.push_back({s,startTime[i]});
                s = endTime[i];
            }
            else if(s == startTime[i]) {
                if(free.size()>0) {
                    free.push_back({s,startTime[i]});
                }
                s = endTime[i];
            }
        }
        if(endTime[n-1] < eventTime) free.push_back({s,eventTime});
        for(int i =0; i<free.size(); i++) cout<<free[i].first<<" "<<free[i].second<<endl;
        if(free.size() == 0) return 0;
        if(free.size() == 1) return free[0].second - free[0].first;
        if(free.size() <= k+1) {
            int ans = 0;
            for(int i = 0;i<free.size();i++) {
                ans+=free[i].second - free[i].first;
            }
            return ans;
        }
        int mxans = 0;
        int ans = 0;
        for(int i =0; i<=k; i++) {
            ans += free[i].second - free[i].first;
        }
        mxans = max(ans,mxans);
        s = 0;
        e = k;
        while(e+1<free.size()) {
            ans -= (free[s].second - free[s].first);
            s++;
            e++;
            ans += free[e].second - free[e].first;
            mxans = max(ans, mxans);
        }
        return mxans;
    }
};
