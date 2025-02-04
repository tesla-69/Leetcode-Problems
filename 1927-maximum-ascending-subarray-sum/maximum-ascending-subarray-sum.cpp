class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = INT_MIN;
        int n = nums.size();
        int sum = nums[0];
        ans = max(ans,sum);
        for(int i=1 ;i <n; i++) {
            if(nums[i]>nums[i-1]) {
                sum += nums[i];
                ans = max(ans,sum);
            }
            else {
                sum = nums[i];
                ans = max(ans,sum);
            }
        }
        return ans;
    }
};