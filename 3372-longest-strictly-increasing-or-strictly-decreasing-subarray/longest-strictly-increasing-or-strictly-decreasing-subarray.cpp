class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int incmx = 0;
        int decmx = 0;
        int cntinc = 1;
        int cntdec = 1;
        int n = nums.size();
        if(n==1) return 1;
        for(int i =1; i<n; i++) {
            if(nums[i]>nums[i-1]) {
                cntinc++;
                incmx = max(incmx,cntinc);
                cntdec = 1;
            }
            else if(nums[i] < nums[i-1]){
                cntdec++;
                decmx = max(decmx,cntdec);
                cntinc = 1;
            } 
            else {
                cntinc = 1;
                incmx = max(incmx,cntinc);
                cntdec = 1;
                decmx = max(decmx,cntdec);
            }
        }
        return max(decmx,incmx);
    }
};