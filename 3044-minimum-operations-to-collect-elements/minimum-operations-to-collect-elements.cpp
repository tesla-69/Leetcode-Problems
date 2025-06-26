class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        bool seen[51] = {0};
        int count = 0, n = nums.size();
        for(int i = n - 1; i >= 0; --i){
            int num = nums[i];
            if(num <= k && !seen[num]){
                if(++count == k) return n - i;
                seen[num] = true;
            }
        }
        return n;
    }
};