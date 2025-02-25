int MOD = 1e9 + 7;
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> pre(n+1,0);
        for(int i =0; i<n;i++) {
            pre[i+1] = pre[i] + arr[i];
        }
        int evencnt = 0;
        int oddcnt = 0;
        long long ans = 0;

        for(int i =0; i<=n; i++) {
            if(pre[i] & 1) {
                ans = (ans + evencnt) % MOD;
                oddcnt++;
            } 
            else {
                evencnt++;
                ans = (ans + oddcnt) % MOD;
            }
        }
        ans = ans % MOD;
        return ans;
    }
};