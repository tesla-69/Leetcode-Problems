class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        for(int i = 1; i < n; i++) ans.push_back(i);
        int val =( n * (n - 1) ) / 2;
        ans.push_back(val*-1);
        return ans;
    }
};