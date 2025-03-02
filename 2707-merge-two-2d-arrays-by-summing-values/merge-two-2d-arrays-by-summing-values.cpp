class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int n = nums1.size();
        int m = nums2.size();
        int i = 0 , j = 0;
        while(i < n || j < m) {
            int id1 = 1001, id2 = 1002;
            if(i < n) id1 = nums1[i][0];
            if(j < m)  id2 = nums2[j][0];
            if(id1 == id2) {
                ans.push_back({id1,nums1[i][1]+nums2[j][1]});
                i++;
                j++;
            }
            else if(id1 < id2) {
                ans.push_back({id1,nums1[i][1]});
                i++;
            }
            else {
                ans.push_back({id2,nums2[j][1]});
                j++;
            }
        }
        return ans;
    }
};