class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        vector<int> diffArr(n,0);
        int m = q.size();
        for(int k = 0; k < m; k++) {
            int i = q[k][0], j = q[k][1];
            diffArr[i] += 1;
            if(j != n-1) diffArr[j+1] -= 1;
        }
        for(int i = 1; i < n; i++) {
            diffArr[i] += diffArr[i-1];
            if(nums[i] > diffArr[i]) return false;
        }
        return nums[0] <= diffArr[0];
    }
};