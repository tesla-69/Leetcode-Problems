class Solution {
public:
    long long coloredCells(int n) {
        return 1 + 2 * (n-1) * 1LL * n * 1LL;
    }
};