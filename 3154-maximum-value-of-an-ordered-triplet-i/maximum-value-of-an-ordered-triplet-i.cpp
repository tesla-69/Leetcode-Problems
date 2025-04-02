class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long val = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                for(int k = j+1; k < n; k++) {
                    long long temp = (nums[i] - nums[j]);
                    temp *= nums[k];
                    val = max(val, temp);
                }
            }
        }
        return val;
    }
};