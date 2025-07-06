class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int n = gain.size();
        vector<int> pre(n+1, 0);
        for(int i = 0; i < n; i++) {
            pre[i+1] = pre[i] + gain[i];
            ans = max(ans, pre[i+1]);
        }
        return ans;
    }
};