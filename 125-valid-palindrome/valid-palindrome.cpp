class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
        string check;
        for(int i=0;i<n;i++){
            if((s[i]>='a' && s[i]<='z') || (s[i] >= '0' && s[i] <= '9')) check += s[i];
            else if(s[i] >= 'A' && s[i] <= 'Z') check += s[i] - 'A' + 'a';
        }
        string temp = check;
        reverse(temp.begin(), temp.end());
        return temp == check;

    }
};