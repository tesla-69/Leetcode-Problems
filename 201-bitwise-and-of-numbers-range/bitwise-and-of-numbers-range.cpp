class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int bl = (left & (1<<i)) == 0?0:1;
            int br = (right & (1<<i)) == 0?0:1;
            if (bl == 1 and br == 1) {
                if (right - left < (1<<i)) {
                    res ^= (1<<i);
                }
            }
        }
        return res;
    }
};