class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long cnt = 0;
        int n = nums.size();
        int i = 0, j = 0;
        int mx = *max_element(nums.begin(), nums.end());
        int ele = 0;
        while(j < n) {
            if(nums[j] == mx) {
                ele++;
                if(ele == k) {
                    cnt += n - j;
                    while(i <= j && nums[i] != mx) {
                        cnt += n - j;
                        i++;
                    }
                    ele--;
                    i++;
                }
            }
            j++;
        }
        return cnt;
    }
};