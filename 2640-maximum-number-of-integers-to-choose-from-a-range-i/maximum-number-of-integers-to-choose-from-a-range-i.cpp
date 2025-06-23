class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        map<int,int> mp;
        int nn = banned.size();
        for(int i = 0; i < nn; i++) mp[banned[i]] = 1;
        int cnt = 0;
        int sum = 0;
        for(int i = 1; i <= n; i++) {
            if(mp[i] == 0) {
                if(sum + i <= maxSum) {
                    sum += i;
                    cnt++;
                }
                else break;
            }
        }
        return cnt;
    }
};