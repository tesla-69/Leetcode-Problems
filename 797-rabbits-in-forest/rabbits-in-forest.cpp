class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int> mp;
        int n = answers.size();
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(mp[answers[i]] == 0) {
                mp[answers[i]] = answers[i];
                cnt += answers[i] + 1;
            }
            else {
                mp[answers[i]]--;
            }
        }
        return cnt;
    }
};