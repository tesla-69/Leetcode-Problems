class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end(), [&](vector<int>a, 
        vector<int> b) {
            return a[0] < b[0];
        });

        vector<vector<int>> ans;
        ans.push_back(arr[0]);
        int j = 0;
        int n = arr.size();
        for(int i = 1; i < n; i++) {
            if(ans[j][1] >= arr[i][0]) {
                ans[j][1] = max(ans[j][1], arr[i][1]);
            }
            else {
                ans.push_back(arr[i]);
                j++;
            }
        }
        return ans;
    }
};