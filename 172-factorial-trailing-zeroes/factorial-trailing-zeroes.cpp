class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        for(int i =1;i<=n;i++) {
            int num = i;
            if(num % 10 == 0) {
                while(num%10 == 0) {
                    num /= 10;
                    ans++;
                }
                while(num % 5 == 0) {
                    num /= 5;
                    ans++;
                }
            } 
            else if(num % 5 == 0) {
                while(num % 5 == 0) {
                    num /= 5;
                    ans++;
                }
            }
        }
        return ans;
    }
};