class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftmax(n) , rightmin(n);
        leftmax[0] = nums[0];
        rightmin[n-1] = nums[n-1];
        for(int i = 1;i < n; i++) {
            leftmax[i] = max(leftmax[i-1], nums[i]);
        }
        for(int i = n-2;i>=0; i--) {
            rightmin[i] = min(rightmin[i+1], nums[i]);
        }
        for(int i = 0; i <n-1; i++) {
            if(leftmax[i] <= rightmin[i+1]) {
                return i+1;
            }
        }
        return 0;
    }
};