class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26,0);
        int n = s.length();
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        sort(freq.begin(),freq.end());
        int od = INT_MIN;
        int ev = INT_MAX;
        // for(int i = 0 ;i<26;i++) cout<<freq[i]<<" ";
        // cout<<endl;
        for(int i = 0; i< 26;i++){
            if(freq[i] & 1) od = max(od,freq[i]);
            else if(ev == 0) ev = max(ev,freq[i]);
            else if(ev != 0) ev = min(ev,freq[i]);
        }
        // cout<<od<< " "<<ev;
        return od - ev;
    }
};