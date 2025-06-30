class Solution {
public:
    bool solve(int i, vector<int>& nums, long long& tar, long long mul) {
        if (i < 0)
            return false;
        if(nums[i] * mul == tar) return true;

        int take = false;
        if (mul * nums[i] <= tar)
            take = solve(i - 1, nums, tar, mul * nums[i]);
        int ntake = solve(i - 1, nums, tar, mul);

        return take || ntake;
    }

    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n = nums.size();
        __int128 mul = 1;
        for (int x : nums)
            mul *= x;
        __int128 t = target;
        if (mul != t * t)
            return false;

        return solve(n - 1, nums, target, 1);
    }
};