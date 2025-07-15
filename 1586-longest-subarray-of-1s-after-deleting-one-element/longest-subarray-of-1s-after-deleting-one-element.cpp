class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int maxi = 0;
        int cnt = 0;
        for(auto it:nums){
            if(it) cnt++;
        }
        if(cnt == n) return n-1;
        while(j < n) {
            j = i;
            int curr = 0;
            bool one = true;
            while(j < n) {
                if(nums[j]) curr++;
                else {
                    if(!one) break;
                    i = j + 1;
                    one = false;
                }
                j++;
            }
            maxi = max(maxi, curr);
        }
        return maxi;
    }
};