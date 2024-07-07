class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        sort(meetings.begin(), meetings.end());
        using p = pair<long, int>;
        priority_queue<p, vector<p>, greater<p>> usedRooms;
        priority_queue<int, vector<int>, greater<int>> roomsAvailable;
        for(int i = 0 ; i < n ; i++)
            roomsAvailable.push(i);
        vector<int> mostMeetings(n);
        for(int i = 0 ; i < m ; i++){
            int srtTime = meetings[i][0], endTime = meetings[i][1], duration = endTime - srtTime;
            while(usedRooms.size() && srtTime >= usedRooms.top().first){
                roomsAvailable.push(usedRooms.top().second);
                usedRooms.pop();
            }
            if(roomsAvailable.size()){
                int room = roomsAvailable.top();
                roomsAvailable.pop();
                usedRooms.push({endTime, room});
                mostMeetings[room]++;
            }
            else{
                auto[minEndTime, room] = usedRooms.top();
                usedRooms.pop();
                usedRooms.push({minEndTime + duration, room});
                mostMeetings[room]++;
            }
        }

        int maxMeetings = 0, reqRoom = -1;
        for(int i = 0 ; i < n ; i++){
            if(mostMeetings[i] > maxMeetings){
                maxMeetings = mostMeetings[i];
                reqRoom = i;
            }
        }
        return reqRoom;
    }
};