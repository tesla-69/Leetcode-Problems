class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(s.begin(),s.end());
        // sort(t.begin     ),t.end());
        // return s == t;
        if(s.length() != t.length()) return false;
        unordered_map<char,int>mp;
        for(int i =0;i<s.length();i++) mp[s[i]]++;
        for(int i =0;i<t.length();i++){
            if(mp[t[i]] == 0) return false;
            mp[t[i]]--;
        } 
        return true;
    }
};