class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> arr;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end(), [&](pair<int,int>a, pair<int, int>b){
            return a.first < b.first;
        });

        vector<pair<int,int>> ans;
        int i = n-1;
        while(k--) {
            ans.push_back(arr[i]);
            i--;
        }
        sort(ans.begin(), ans.end(), [&](pair<int,int>a, pair<int,int>b) {
            return a.second < b.second;
        });

        vector<int> a;
        for(auto it: ans) {
            a.push_back(it.first);
        }
        return a;

    }
};