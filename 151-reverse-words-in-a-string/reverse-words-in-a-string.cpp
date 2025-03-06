class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i= 0;
        string ans;
        while(i < n) {
            string temp;
            while(i<n && s[i] == ' ') i++;
            if(i == n) break;
            while(i<n && s[i] != ' ') {
                temp += s[i];
                i++;
            }
            temp += ' ';
            string a = ans;
            ans = temp;
            ans += a;
        }
        ans = ans.substr(0,ans.size()-1);
        return ans;
    }
};