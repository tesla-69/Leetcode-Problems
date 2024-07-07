class Solution {
public:
    void dfs(int person , unordered_set<int> &secret_keepers , unordered_set<int> &AlreadyTraversed , unordered_map<int,vector<int>> &AdjacencyList){
        for(int adj_person : AdjacencyList[person]){
            if(AlreadyTraversed.find(adj_person) != AlreadyTraversed.end()){
                continue;
            }
            secret_keepers.insert(adj_person);
            AlreadyTraversed.insert(adj_person);
            dfs(adj_person , secret_keepers , AlreadyTraversed , AdjacencyList);
        }

        return ; 
    };
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
 
        for(vector<int> &meeting : meetings){
            int xi = meeting[0];
            int yi = meeting[1];
            int ti = meeting[2];
            meeting = {ti , xi , yi};
        }   

        sort(meetings.begin() , meetings.end());

        unordered_set<int> know_secrets = {0 , firstPerson};

        vector<vector<vector<int>>> clusters;
        int index = 0;
        while(index < meetings.size()){
            int time = meetings[index][0];
            vector<vector<int>> curr_cluster = {};
            while(index < meetings.size() && meetings[index][0] == time){
                curr_cluster.push_back(meetings[index++]);
            }
            clusters.push_back(curr_cluster);
        }

        unordered_set<int> secret_keepers = {0 , firstPerson};
        for(auto &cluster : clusters){

            vector<vector<int>> &curr_cluster = cluster;

            // adjacency list
            unordered_map<int,vector<int>> AdjacencyList;
            vector<int> people = {};
            unordered_set<int> AlreadyTraversed;
            for(vector<int> meeting : curr_cluster){
                int u = meeting[1];
                int v = meeting[2];
                AdjacencyList[u].push_back(v);
                AdjacencyList[v].push_back(u);
                people.push_back(u);
                people.push_back(v);
            }


            for(int person : people){
               
                if(secret_keepers.find(person) != secret_keepers.end() && AlreadyTraversed.find(person) == AlreadyTraversed.end()){
                    AlreadyTraversed.insert(person);
                    dfs(person , secret_keepers , AlreadyTraversed , AdjacencyList);
                }
            }
        }

        vector<int> OutputArr;
        for(int person : secret_keepers){
            OutputArr.push_back(person);
        }
        sort(OutputArr.begin() , OutputArr.end());

        return OutputArr;
    }
};