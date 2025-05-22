class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int n = s.size();
        int i = 0;
        while(i < n) {
            cout<<i<<" ";
            while(i < n && s[i] == ' ') i++;
            cout<<i<<" ";
            string temp;
            while( i < n && s[i] != ' ') {
                temp += s[i];
                i++;
            }
            cout<<temp<<endl;
            if(temp != "")
            st.push(temp);
        }
        string ans;
        while(!st.empty()) {
            cout<<st.top()<<endl;
            ans += st.top();
            st.pop();
            ans += ' ';
        }
        ans.pop_back();
        return ans;
        
    }
};