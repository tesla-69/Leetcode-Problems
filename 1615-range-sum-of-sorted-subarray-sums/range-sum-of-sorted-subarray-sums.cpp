#define mod 1000000007
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sum;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int curr = 0;
                for(int k=i; k<=j; k++){
                    curr += nums[k];
                }
                sum.push_back(curr);
            }
        }
        sort(sum.begin(),sum.end());
        int ans = 0;
        for(int i=left-1; i<right; i++){
            ans = (ans + sum[i]) % mod;
        }
        return ans;
    }
};