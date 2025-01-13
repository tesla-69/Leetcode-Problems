class Solution {
public:
    int minimumLength(string s) {
        int a[26] = {0};
        for(auto ch : s){
            a[ch-'a']++;
        }
        int ans = 0;
        for(int i =0; i< 26; i++) {
            if(a[i]&1 && a[i]>1){
                ans+=a[i]-1;
            }
            else if(a[i]%2 ==0 && a[i] > 2){
                ans+=a[i]-2;
            }
        }
        ans = s.length() - ans;
        return ans;
    }
};