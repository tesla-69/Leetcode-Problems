class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int len=0;
        for(int i =n-1;i>=0;i--){
            if(len!=0 && s[i]==' '){
                break;
            }
            else if(s[i]!=' ') len++;
        }
        return len;
    }
};