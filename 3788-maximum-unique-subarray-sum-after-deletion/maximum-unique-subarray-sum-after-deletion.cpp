class Solution {
public:
    int maxSum(vector<int>& nums) {
        int maxi = INT_MIN;
        int curr = 0;
        set<int> arr;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= 0) arr.insert(nums[i]);
            maxi = max(maxi, nums[i]);
        }
        if(arr.size() == 0) return maxi;

        maxi = accumulate(arr.begin(), arr.end(), 0);
        return maxi;

    }
};