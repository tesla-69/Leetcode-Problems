class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mp;
        int n = words.size();
        int len = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            string curr = words[i];
            string rev = curr;
            if(rev[0] == rev[1]) {
                if(mp[rev] != 0) {
                    len += 4;
                    mp[rev]--;
                    cnt--;
                    continue;
                }
                else cnt++;
            }
            swap(rev[0],rev[1]);
            if(mp[rev] != 0) {
                len += 4;
                mp[rev]--;
            } 
            else {
                mp[curr]++;
            }
        }   
        if(cnt > 0) len += 2;
        return len;
    }
};