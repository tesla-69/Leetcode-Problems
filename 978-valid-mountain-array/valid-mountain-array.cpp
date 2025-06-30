class Solution {
public:
    bool validMountainArray(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return false;
        int i = 1;
        int j = n - 2;
        while(i < n && nums[i] > nums[i-1]) {
            i++;
        }
        i--;
        while(j >= 0 && nums[j] > nums[j + 1]) j--;
        j++;
        cout<<i << " " << j;
        if(i == 0 || j == n-1) return false;
        return i == j;
    }
};