class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diffArr(n,0);
        for(auto it: queries) {
            int i = it[0];
            int j = it[1];
            // cout<<i<<" "<<j<<endl;
            diffArr[i] += 1;
            if(j != n-1) diffArr[j+1] -= 1;
        }
        for(int i = 1; i < n; i++) {
            diffArr[i] += diffArr[i-1];
        }
        // for(int i = 0; i < n; i++){
        //     cout<<diffArr[i]<<" ";
        // }
        for(int i = 0; i < n; i++) {
            if(nums[i] > diffArr[i]) return false;
        }
        return true;
    }
};