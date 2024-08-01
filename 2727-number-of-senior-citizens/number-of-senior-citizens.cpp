class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0 ;
        for(auto s : details){
            string a = "";
            a+=s[11];
            a+=s[12];
            int age = stoi(a);
            if(age>60) ans++;
        }
        return ans;
    }
};