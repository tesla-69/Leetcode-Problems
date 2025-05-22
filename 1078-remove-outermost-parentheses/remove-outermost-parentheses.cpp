class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        int n = s.size();
        string ans;
        int i = 0;
        while(i < n) {
            if(st.empty()) {
                string temp;
                st.push(s[i]);
                i++;
                while(!st.empty()) {
                    if(s[i] == '(') {
                        st.push(s[i]);
                    }
                    else st.pop();
                    temp += s[i];
                    i++;
                }
                temp.pop_back();
                ans += temp;
            }
        }
        return ans;
    }
};