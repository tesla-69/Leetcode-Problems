class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int n = nums.size();
        int mini = nums[0];
        for(int i = 1; i < n; i++) {
            if(nums[i] - mini > k) {
                cnt++;
                mini = nums[i];
            }
        }
        cnt++;
        return cnt;
    }
};