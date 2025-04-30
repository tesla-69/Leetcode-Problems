class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int t = ceil(log10(nums[i]));
            if(pow(10,t) == nums[i]) t++;
            if(!(t & 1)) cnt++;
        }
        return cnt;
        
    }
};