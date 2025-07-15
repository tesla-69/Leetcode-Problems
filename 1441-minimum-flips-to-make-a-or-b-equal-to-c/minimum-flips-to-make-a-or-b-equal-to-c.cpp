class Solution {
public:
    int minFlips(int a, int b, int c) {
        int num = c;
        int cnt = 0;
        while(num) {

            cout << (num & 1) << " ";
            int num1 = 0;
            int num2 = 0;
            if(a != 0) {
                num1 = a & 1;
                a >>= 1;
            }
            if(b != 0) {
                num2 = b & 1;
                b >>= 1;
            }
            cout << num1 <<" "<<num2<<" ";
            if((num & 1) && (!num1 && !num2)) cnt++;
            else if(!(num & 1)) {
                if(num1) cnt++;
                if(num2) cnt++;
            }
            num >>= 1;
            cout<<cnt<<endl;
        }
        while(a) {
            if(a&1) cnt++;
            a >>= 1;
        }
        while(b) {
            if(b&1) cnt++;
            b >>= 1;
        }
        return cnt;
    }
};