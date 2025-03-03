class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int scnt = 0, ecnt = 0, gcnt = 0;
        int n = nums.size();
        for(int i =0; i<n; i++) {
            if(nums[i] < pivot) scnt++;
            else if (nums[i] == pivot) ecnt++;
            else gcnt++;
        }
        vector<int> ans(n);
        int s =0, e=scnt, g=scnt+ecnt;
        for(int i =0; i<n ;i++) {
            if(nums[i] < pivot){
                ans[s] = nums[i];
                s++;
            } 
            else if(nums[i] == pivot) {
                ans[e] = nums[i];
                e++;
            }
            else {
                ans[g] = nums[i];
                g++;
            }
        }
        return ans;
    }
};