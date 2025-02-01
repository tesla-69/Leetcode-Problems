class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int n = nums.size();
        for(int i = 1;i<n;i++){
            int sum = nums[i-1]+nums[i];
            if(!(sum&1)) return 0;
        }         
        return 1;
    }
};