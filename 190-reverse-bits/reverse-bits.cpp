class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        cout<<n<<endl;
        bitset<32> binary(n);
        string s = binary.to_string();
        cout<<s<<endl;
        int i = 0;
        int j = s.length()-1;
        for(int i =0;i<=j;i++){
            if(s[i] == '1') {
                ans += pow(2,i);
            }
        }
        return ans;
        // while(i<j){
        //     swap(s[i],s[j]);
        //     i++;j--;
        // }

    }
};