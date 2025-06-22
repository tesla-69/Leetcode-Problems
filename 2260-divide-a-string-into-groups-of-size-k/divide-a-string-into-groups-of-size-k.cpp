class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.size();
        if(n < k) {
            for(int i = 0; i < k - n; i++) s += fill;
        }
        int num = n % k;
        if(num != 0) num = n - num;
        for(int i = 0; i < num; i++) s += fill;
        // cout<<s<<" ";
        // cout<<n;
        for (int i = 0; i < max(n, k); i += k) {
            // cout<<i<<" ";
            string t = s.substr(i, k);
            // cout<<t<<" ";
            ans.push_back(t);
        }
        return ans;
    }
};