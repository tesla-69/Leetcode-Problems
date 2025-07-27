class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int i = 0;
        int j = 1;
        while(j < n && nums[j] == nums[i]) j++;
        int k = j;
        while(k < n && nums[j] == nums[k]) k++;
        while(k < n) {
            if(nums[j] > nums[i] && nums[j] > nums[k]) cnt++;
            else if(nums[j] < nums[i] && nums[j] < nums[k]) cnt++;

            i = j;
            j = k;
            k++;
            while(k < n && nums[j] == nums[k]) k++;
        }
        return cnt;
    }
};