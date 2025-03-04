class Solution {
public:
    bool checkPowersOfThree(int n) {
        int x = n;
        int p = 15;
        while(x && p+1) {
            int num = pow(3,p);
            cout<<x<<" ";
            if(num <= x) {
                x -= num;
            }
            p--;
        }
        cout<<x<<" ";
        if(x == 0) return 1;
        else return 0;
    }
};