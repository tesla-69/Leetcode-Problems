class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum = 0;
        int digitsum = 0;
        int n = nums.size();
        for(auto it: nums) {
            sum += it;
            while(it) {
                int t = it % 10;
                digitsum += t;
                it /= 10;
            }
        }
        int ans = abs(sum - digitsum);
        return ans;
    }
};