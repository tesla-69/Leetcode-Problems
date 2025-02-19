class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto ch : s) {
            if(st.empty()) st.push(ch);
            else {
                if(ch == '(' || ch == '{' || ch == '[') st.push(ch);
                else {
                    if(ch == ')' && st.top() == '(') st.pop();
                    else if(ch == '}' && st.top() == '{') st.pop();
                    else if(ch == ']' && st.top() == '[') st.pop();
                    else return false; 
                }
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};