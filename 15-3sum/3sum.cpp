class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        set<pair<int,pair<int,int>>> s;
        sort(nums.begin(),nums.end());
        for(int i = 0; i< n-2; i++) {
            int j = i+1;
            int k = n-1;
            while(j<k) {
                if(nums[i] + nums[j] + nums[k] == 0) {
                    s.insert({nums[i],{nums[j],nums[k]}});
                    j++;
                    k--;
                }
                else if(nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                }
                else j++;
            }
        }
        for(auto it : s) {
            vector<int>t;
            t.push_back(it.first);
            t.push_back(it.second.first);
            t.push_back(it.second.second);
            ans.push_back(t);
        }
        return ans;
    }
};