class Solution {
public:

    bool isvowel(char ch) {
        string vowel = "aeiou";
        if(vowel.find(ch) != string::npos) return true;
        else return false;
    }

    int maxVowels(string s, int k) {
        int n = s.size();
        int i = 0;
        int j = 0;
        int maxi = 0;
        int cnt = 0;
        while(j < k) {
            if(isvowel(s[j])) cnt++;
            maxi = max(maxi, cnt);
            j++; 
        }
        while(j < n) {
            if(isvowel(s[i])) cnt--;
            if(isvowel(s[j])) cnt++;
            i++; 
            j++;
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};