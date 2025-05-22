class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pre = strs[0];
        int n = strs.size();
        for(int i = 1; i < n; i++) {
            string s = strs[i];
            int j = 0;
            int len = min(s.size(), pre.size());
            while(j < len && pre[j] == s[j]) j++;
            pre = pre.substr(0, j);
        }
        return pre;
    }
};