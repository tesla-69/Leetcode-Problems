class Solution {
public:
    int mySqrt(int x) {
        long long i;
        for( i = 1;i*i<=x;i++){
            if(i*i == x) return i;
            else if(i*i > x) return i-1;
        }
        return i-1;
    }
};