class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length() < k) return false;
        vector<int> cnt(26,0);
        for(char &ch : s){
            cnt[ch-'a']++;
        }
        int oddcnt=0;
        for(int i = 0 ; i < 26 ; i++) {
            if(cnt[i]&1) oddcnt++; 
        }
        int evencnt = s.length() - oddcnt;
        // k = k - oddcnt;
        // if(k>=0) return true;
        // else {
        //     if(evencnt/2  )
        // } 
        if(k< oddcnt) return false;
        else{
            k-=oddcnt;
            if(k<=evencnt) return true;
            else return false;
        }
        return false;
    }
};