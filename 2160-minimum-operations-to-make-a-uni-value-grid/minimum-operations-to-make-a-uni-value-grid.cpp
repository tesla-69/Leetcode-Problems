class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> arr;
        for(int i = 0; i < n; i++) {
            for(int j=0; j<m; j++) {
                arr.push_back(grid[i][j]);
            }
        }
        sort(arr.begin(), arr.end());
        int mid = arr[(n*m)/2 - !((n*m) & 1)] ;
        for(int i = 1; i< n*m; i++) {
            if((arr[i] - arr[i-1]) % x != 0) return -1; 
        }
        cout<<mid<<endl;
        int ans = 0;
        for(int i = 0; i<n*m; i++) {
            ans += (abs(arr[i] - mid)) / x;
        }
        return ans;
    }
};