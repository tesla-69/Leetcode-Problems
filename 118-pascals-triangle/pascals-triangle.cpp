class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if (numRows == 1) {
            ans.push_back({1});
            return ans;
        }
        else if (numRows == 2) {
            ans.push_back({1});
            ans.push_back({1, 1});
            return ans;
        }
        else {
            ans.push_back({1});
            ans.push_back({1,1});
            for(int i=2;i<numRows;i++){
                vector<int> arr;
                arr.push_back(1);
                for(int j=1;j<i;j++){
                    int temp=ans[i-1][j-1]+ans[i-1][j];
                    arr.push_back(temp);
                }
                arr.push_back(1);
                ans.push_back(arr);
            }
            return ans;
        }
    }
};