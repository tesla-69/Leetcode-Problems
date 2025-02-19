class Solution {
public:
    bool solve(int n, int &k, string s, string& ans){
        if(s.length() == n){
            k--;
            if(k==0) {
                ans = s;
                return true;
            }
            else return false;
        }
        for(int i =0;i <3;i++){
            if(s.length() !=0 && s.back() == i + 'a') continue;
            s += i + 'a';
            if(solve(n, k, s,ans)==true) {
                return true;
            }
            else {
                s.pop_back();
            }
        }
        return false;
    }
    string getHappyString(int n, int k) {
        string ans;
        string s;
        if(solve(n,k,s,ans) == true) return ans;
        else return "";
    }
};