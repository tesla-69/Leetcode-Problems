class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        int i = 0;
        while(i < n) {
            int j = 3;
            vector<int> temp;
            while(j--){
                temp.push_back(nums[i]);
                i++;
            }
            ans.push_back(temp);
        }
        for(auto it: ans) {
            if(it[2] - it[0] > k) {
                vector<vector<int>> t;
                return t;
            }
        }
        return ans;
    }
};