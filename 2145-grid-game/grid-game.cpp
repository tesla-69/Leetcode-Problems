#define ll long long
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<ll> suf(n+1,0);
        vector<ll> pre(n+1,0);
        for(int i = n-1; i>=0 ; i--) {
            suf[i] = suf[i+1] + grid[0][i];
        }
        for(int i = 0; i<n ; i++) {
            pre[i+1] = pre[i] + grid[1][i];
        }
        ll ans = LLONG_MAX;
        for(int i =0 ; i < n; i++) {
            ans = min(ans,max(suf[i+1], pre[i]));
        }
        return ans;
    }
};