class Solution {
public:
    long long coloredCells(int n) {
        int x = 4;
        long long ans = 1;
        n--;
        while(n--){
            ans += x;
            x += 4;
        }
        return ans;
    }
};