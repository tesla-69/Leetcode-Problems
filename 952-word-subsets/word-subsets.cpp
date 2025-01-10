class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        map<char,int> mxcnt;
        vector <string> ans;
        for(auto word : words2){
            map<char,int> temp;
            for(auto ch : word){
                temp[ch]++;
                mxcnt[ch] = max(mxcnt[ch], temp[ch]);
            }
        }
        for(auto a : words1) {
            map<char,int> wordA;
            for(auto ch : a){
                wordA[ch]++;
            }
            int f = 0;

            for(char i = 'a' ;i<= 'z';i++){
                if(mxcnt[i] > wordA[i]){
                    f=1;
                    break;
                }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
            }
            if(f==1) continue;
            else ans.push_back(a);
        }
    return ans;
    }
};