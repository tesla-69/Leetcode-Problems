class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        unordered_map<int,int> mp;
        int sum = 0;
        mp[0] = 1;  // Initialize to 1
        
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if(mp.find(sum - k) != mp.end()) {
                cnt += mp[sum - k];  // Count occurrences of (sum - k)
            }

            mp[sum]++;  // Store current sum frequency
        }
        return cnt;
    }
};
