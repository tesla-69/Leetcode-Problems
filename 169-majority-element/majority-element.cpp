class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mp;
        int n = nums.size();
        for(int i =0 ; i < nums.size();i++) mp[nums[i]]++;
        int ans ;
        for(auto it : mp) {
            if(it.second > n/2) ans = it.first;
        }
        return ans;
    }
};