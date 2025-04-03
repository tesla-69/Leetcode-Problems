class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long val = 0;
        int n = nums.size();
        vector<int> pre(n+1, 0) , suf(n+1,0);
        pre[0] = nums[0];
        suf[n] = nums[n-1];
        for(int i = 0; i<n; i++) {
            pre[i+1] = max(pre[i], nums[i]);
        }
        for(int i = n-1; i >= 0; i--) {
            suf[i] = max(suf[i+1], nums[i]);
        }
        // for(int i = 0; i<=n; i++) cout<<pre[i]<<" ";
        // cout<<endl;
        // for(int i = 0; i<=n; i++) cout<<suf[i]<<" ";
        // cout<<endl;
        for(int i = 1; i<n-1; i++) {
            long long t = (pre[i] - nums[i]);
            t *= suf[i+1];
            val = max(t, val);
        }
        return val;
    }
};