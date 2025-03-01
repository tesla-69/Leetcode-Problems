class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int n = original.size();
        int l = bounds[0][0];
        int h = bounds[0][1];
        int cnt = max(h-l+1,0);
        for(int i = 1; i<n; i++) {
            int diff = original[i] - original[i-1];
            l = max(l + diff , bounds[i][0]);
            h = min(h + diff , bounds[i][1]);
            cnt = min(cnt,h-l+1);
        }
        cnt = max(cnt,0);
        return cnt;
    }
};