class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        map<int,int> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }
        for(auto it: operations) {
            nums[mp[it[0]]] = it[1];
            mp[it[1]] = mp[it[0]]; 
        }
        return nums;
    }
};