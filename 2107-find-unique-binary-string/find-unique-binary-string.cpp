class Solution {
public:
    bool solve(string s , string& ans, int n, set<string> st){
        if(s.length() == n){
            if(st.find(s) == st.end()) {
                ans = s;
                return true;
            }
            else return false;
        }
        for(int i =0;i<2;i++){
            s += i + '0';
            if(solve(s,ans,n,st) == true) return true;
            else s.pop_back();
        }
        return false;

    }
    string findDifferentBinaryString(vector<string>& nums) {
        set<string> st;
        for(int i =0;i<nums.size();i++) st.insert(nums[i]);
        int n = nums[0].length();
        string ans ;
        string s;
        if(solve(s,ans,n,st) == true) return ans;
        else return "";
    }
};