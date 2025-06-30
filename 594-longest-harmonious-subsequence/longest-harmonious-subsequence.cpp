class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxi = 0;
        int s = 0;
        int e = 1;
        
        while(e < n) {
            while(e < n && nums[s] == nums[e]) e++;
            if(e == n) break;
            if(nums[e] - nums[s] == 1) {
                e++;
                maxi = max(e - s, maxi);
            }
            else {
                if(e-s > 1) s++;
                else {
                    s++;
                    e++;
                }
            }
        }
        return maxi;
    }
};