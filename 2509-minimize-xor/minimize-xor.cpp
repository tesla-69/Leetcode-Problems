class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int temp = num2;
        int cnt = 0;
        while (temp) {
            if (temp & 1)
                cnt++;
            temp >>= 1;
        }
        // cout<<cnt<<endl;
        // return 0;
        int cnt1 = 0;
        temp = num1;
        while (temp) {
            if (temp & 1)
                cnt1++;
            temp >>= 1;
        }
        if (cnt1 == cnt)
            return num1;
        else if (cnt1 > cnt) {
            int diff = cnt1 - cnt;
            int var = num1;
            int x = num1;
            for (int i = 0; i < diff; i++) {
                int c = 0;
                while (1) {
                    if (var & 1)
                        break;
                    c++;
                    var >>= 1;
                }
                x = x & (~(1 << c));
                var = x;
            }
            return x;
        } else {
            int diff = cnt - cnt1;
            int var = num1;
            int x = num1;
            for (int i = 0; i < diff; i++) {
                int c = 0;
                while (1) {
                    if ((var & 1))
                        c++;
                    else
                        break;
                    var>>=1;
                }
                x = x | ((1 << c));
                var = x;
            }
            return x;
        }
    }
};