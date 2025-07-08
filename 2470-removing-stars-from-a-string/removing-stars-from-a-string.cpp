class Solution {
public:
    string removeStars(string ss) {
        stack<char> s;
        string ans;
        for(auto it: ss) {
            if(it == '*') s.pop();
            else s.push(it);
        }
        while(!s.empty()) {
            ans += s.top();
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};