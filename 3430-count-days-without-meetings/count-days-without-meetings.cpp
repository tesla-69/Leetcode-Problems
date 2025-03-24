class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(),meetings.end());
        int rem = days;
        rem -= meetings[0][1] - meetings[0][0] + 1;
        int s , e;
        s = meetings[0][0];
        e = meetings[0][1];
        cout<<rem<<" ";
        for(int i = 1; i < n ; i++) {
            s = meetings[i][0];
            if(e >= meetings[i][1]) continue;
            if(s <= e) {
                rem -= meetings[i][1] - e;
                e = meetings[i][1];
            }
            else {
                rem -= meetings[i][1] - meetings[i][0] + 1;
                e = meetings[i][1];
            }
            cout<<rem<<" ";
        }
        cout<<rem<<" ";
        return rem;
    }

};