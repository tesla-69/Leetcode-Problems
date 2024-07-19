class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        int mn = INT_MAX;
        int mx = INT_MIN;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mn= INT_MAX;
                mx=INT_MIN;
                int ele = matrix[i][j];
                for(int k=0;k<m;k++){
                    mn = min(mn,matrix[i][k]);
                }
                for(int k=0;k<n;k++){
                    mx=max(mx,matrix[k][j]);
                }
                if(mx==ele && mn == ele)ans.push_back(ele);
            }
        }
        return ans;
    }
};