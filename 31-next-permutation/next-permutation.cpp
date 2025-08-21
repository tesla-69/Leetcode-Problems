class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(), nums.end());
        // return;

        int n = nums.size();

        int ind = -1;

        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]) {
                ind = i;
                break;
            }
        }

        if(ind == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int ele = 101;

        int nextsmallind = -1;

        for(int i = ind + 1; i < n; i++) {
            if(nums[i] > nums[ind]){
                if(nextsmallind == -1) nextsmallind = i;
                else if(nums[nextsmallind] > nums[i]) nextsmallind = i;
            }
        }

        cout<<nextsmallind<<" "<<ind<<endl;

        swap(nums[ind], nums[nextsmallind]);

        sort(nums.begin() + ind + 1, nums.end());
    }
};