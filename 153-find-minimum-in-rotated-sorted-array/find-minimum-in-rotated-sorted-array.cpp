class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        int mini;
        if(nums[0] < nums[e]) return nums[0];
        while(s < e) {
            int m = s + (e - s) / 2;
            if(nums[m] >= nums[0]) {
                s = m + 1;
            }
            else {
                mini = m;
                e = m;
            }
        }
        return nums[s];
    }
};