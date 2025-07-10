class Solution {
public:
    string decodeString(string s) {
        stack<char>st;
        
        int n = s.size();
        int i = 0;
        while(i < n) {
            if(s[i] != ']'){
                st.push(s[i]);
            }
            else {
                string curr;
                while(st.top() != '[') {
                    curr += st.top();
                    st.pop();
                }
                reverse(curr.begin(), curr.end());
                st.pop();
                string num;
                while(!st.empty() && isdigit(st.top())){
                    num += st.top();
                    st.pop();
                }
                reverse(num.begin(), num.end());
                int sz = stoi(num);
                for(int j = 0; j < sz; j++) {
                    for(auto it: curr) st.push(it);
                }
            }
            i++;
        }
        string ans;
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};