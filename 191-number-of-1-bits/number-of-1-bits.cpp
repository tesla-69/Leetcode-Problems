class Solution {
public:
    int hammingWeight(int n) {
        bitset<32> binary(n);
        int cnt = 0;
        int a = n;
        while(a) {
            if(a&1) cnt++;
            a = a>>1;
        }
        return cnt;
    }
};