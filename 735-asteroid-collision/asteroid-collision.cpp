class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int> s;
        vector<int> ans;
        for(auto it: arr) {
            if(s.empty()) s.push(it);
            else{
                if(it > 0) s.push(it);
                else {
                    if(s.top() < 0) s.push(it);
                    else {
                        while(!s.empty() && s.top() > 0 && s.top() < abs(it)) {
                            s.pop();
                        }
                        if(s.empty()) s.push(it);
                        else if(s.top() < 0) s.push(it);
                        else if(s.top() == abs(it)) {
                            s.pop();
                            continue;
                        }
                    }
                }
            }
        }
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};