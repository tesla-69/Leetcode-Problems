class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        double ans = 0;
        double curr = 0;
        while(j < k) {
            curr += nums[j];
            j++;
        }
        ans = curr / k;
        while(j < n) {
            curr -= nums[i];
            curr += nums[j];
            ans = max(ans, curr / k);
            i++;j++;
        }
        return ans;
    }
};