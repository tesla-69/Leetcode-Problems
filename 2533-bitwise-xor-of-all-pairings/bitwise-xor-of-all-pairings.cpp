class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n & 1 && m & 1) {
            int ans = 0;
            for (int i = 0; i < n; i++)
                ans = ans ^ nums1[i];
            for (int i = 0; i < m; i++)
                ans = ans ^ nums2[i];
            return ans;
        }
        else if (n & 1 && !(m & 1)) {
            int ans = 0;
            for (int i = 0; i < m; i++)
                ans = ans ^ nums2[i];
            return ans;
        }
        else if (!(n & 1) && m & 1) {
            int ans = 0;
            for (int i = 0; i < n; i++)
                ans = ans ^ nums1[i];
            return ans;
        }
        else return 0;
    }
};