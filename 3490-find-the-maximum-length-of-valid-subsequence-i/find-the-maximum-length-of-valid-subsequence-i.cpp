class Solution {
public:

    // int solve(int i, int prev, int type, vector<int>&arr) {
    //     if(i == n) {
    //         return 0;
    //     }
    //     int curr = 0;
    //     if(type) {
    //         if(((prev & 1) && !(arr[i] & 1)) || (!(prev & 1) && (arr[i] & 1)))
    //             curr = 1 + solve(i + 1, curr, type, arr);
    //         else curr = solve(i+1, prev, type, arr);
    //     }
    //     else {
    //         if(((prev & 1) && (arr[i] & 1)) || (!(prev & 1) && !(arr[i] & 1))){
    //             curr = 1 + solve()
    //         }
    //     }
    //     return curr;
    // }

    int maximumLength(vector<int>& nums) {
        int ev = 0;
        int odd = 0;
        int evodd1 = 0, evodd2 = 0;
        bool prev1 = true, prev2 = false;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] & 1) odd++;
            else ev++;
        }
        for(int i = 0; i < n; i++) {
            if(prev1) {
                if(nums[i] & 1) {
                    evodd1++;
                    prev1 = !prev1;
                }
            }
            else {
                if(!(nums[i]&1)) {
                    evodd1++;
                    prev1 = !prev1;
                }
            }
            if(prev2) {
                if(nums[i] & 1) {
                    evodd2++;
                    prev2 = !prev2;
                }
            }
            else {
                if(!(nums[i]&1)) {
                    evodd2++;
                    prev2 = !prev2;
                }
            }
        }
        return max({odd, ev, evodd1, evodd2});

    }
};