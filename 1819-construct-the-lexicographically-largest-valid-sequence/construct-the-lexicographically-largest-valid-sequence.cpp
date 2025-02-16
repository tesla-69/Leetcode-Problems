class Solution {
public:
    bool solve(int n, vector<int>& ans, unordered_set<int>& s, int ind) {

        if (s.size() == n && ind == 2*n-1)
            return true;
        else if(ind == 2*n-1 && s.size() != n) 
            return false;
        if (ans[ind] != 0) {
            if(solve(n, ans, s, ind + 1)) return true;
            else return false;
        }

        for (int i = n; i >= 1; i--) {
            int num = i;
            if (s.find(num) == s.end()) {
                if(num == 1) {
                    if(ans[ind] == 0) {
                        ans[ind] = 1;
                        s.insert(num);
                        if(solve(n, ans, s, ind+1) == true){
                            return true;
                        }
                        else {
                            s.erase(num);
                            ans[ind] = 0;
                            continue;
                        }
                    }
                }
                else if (ans[ind] == 0 && ind + num < 2*n-1 && ans[ind + num] == 0) {
                    ans[ind] = num;
                    ans[ind+i] = num;
                    s.insert(num);
                    if(solve(n, ans, s, ind+1)== true) return true;
                    else {
                        s.erase(num);
                        ans[ind] = 0;
                        ans[ind+i] = 0;
                        continue;
                    }
                }
            }
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        int size = 2 * n - 1;
        vector<int> ans(size, 0);
        unordered_set<int> s;
        solve(n, ans, s, 0);
        return ans;
    }
};