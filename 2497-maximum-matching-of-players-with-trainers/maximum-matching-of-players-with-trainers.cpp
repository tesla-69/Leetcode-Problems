class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        sort(p.rbegin(), p.rend());
        sort(t.rbegin(), t.rend());
        int n = p.size();
        int m = t.size();
        int i = 0; 
        int j = 0;
        int cnt = 0;
        while (i < n && j < m) {
            if(p[i] <= t[j]) {
                cnt++;
                i++;
                j++;
            }
            else i++;
        }
        return cnt;
    }
};