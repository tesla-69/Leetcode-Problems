class Solution {
public:
    bool check(string s , int num, int curr, int i) {
        if(i == s.length()) {
            if(curr == num) return true;
            else return false;
        }
        if(curr > num) return false;
        bool possible = false;
        for(int j =i; j<s.length(); j++) {
            int val = stoi(s.substr(i,j-i+1));
            possible = possible || check(s, num, curr+val, j+1);
        }
        return possible;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i =1; i<=n;i++) {
            int num = i;
            int sq = num * num;
            string s = to_string(sq);
            if(check(s, num, 0, 0)){
                ans += sq;
            }
        }
        return ans;
    }
};