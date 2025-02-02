class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;
        for(int i = 0;i < n-1;i++) {
            if(nums[i] > nums[i+1]) {
                pivot = i;
                break;
            }
        }
        if(pivot == -1) return true;;
        bool ans = true;
        for(int i = pivot+1 ; i<n-1;i++) {
            if(nums[i] <= nums[i+1]) continue;
            else ans = false;
        }
        if(ans && nums[0] >= nums[n-1]) {
            return ans;
        }
        return false;
    }
};