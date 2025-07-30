class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
        }
        int len = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == maxi) {
                len++;
                ans = max(ans, len);
            }
            else len = 0;
        }
        return ans;
    }
};