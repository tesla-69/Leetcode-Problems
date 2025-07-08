class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp1, mp2;
        for(auto it: nums1) mp1[it]++;
        for(auto it: nums2) mp2[it]++;
        vector<vector<int>> ans;
        vector<int> t;
        for(auto it: nums1) {
            if(mp1[it] == -1) continue;
            if(mp2[it] == 0) {
                t.push_back(it);
                mp1[it] = -1;
            }
        }
        ans.push_back(t);
        t = {};
        for(auto it: nums2) {
            if(mp2[it] == -1) continue;
            if(mp1[it] == 0) {
                t.push_back(it);
                mp2[it] = -1;
            }
        }
        ans.push_back(t);
        return ans;
    }
};