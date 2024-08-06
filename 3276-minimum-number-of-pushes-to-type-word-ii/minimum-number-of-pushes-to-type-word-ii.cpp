class Solution {
public:
    int minimumPushes(string word) {
        map<char,int> mp;
        for(auto ch : word){
            mp[ch]++;
        }
        if(mp.size() <= 8){
            return word.size();
        }
        else{
            vector<pair<char,int> > a;
            for(auto it : mp){
                a.push_back(it);
            }
            sort(a.begin(),a.end(),[&](pair<int,int> a, pair<int,int> b){
                return a.second > b.second;
            });
            int ans = 0;
            int k = 1;
            for(int i=0; i<a.size(); i++){
                ans += a[i].second * k;
                if((i+1)%8 == 0) k++;
            }
            return ans;
        }
        return 0;
    }
};