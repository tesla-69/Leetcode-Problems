class Solution {
    int solve(int n, vector<int>& nums, int val){
        if(n < 0) {
            return val;
        }
        int take = solve(n-1, nums, nums[n] ^ val);
        int ntake = solve(n-1, nums, val);
        return take + ntake;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        return solve(n-1, nums, 0);
    }
};