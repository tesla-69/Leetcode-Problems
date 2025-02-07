class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans;
        int cnt = 0;
        int n = queries.size();
        unordered_map<int,int> colormap;
        unordered_map<int,int> ballmap;
        for(int i =0; i<n;i++) {
            if(ballmap[queries[i][0]] == 0) {
                if(colormap[queries[i][1]] == 0){
                    cnt++;
                }
                ans.push_back(cnt);
                colormap[queries[i][1]]++;
                ballmap[queries[i][0]] = queries[i][1];
            }
            else {
                colormap[ballmap[queries[i][0]]]--;
                if(colormap[ballmap[queries[i][0]]] == 0) {
                    if(colormap[queries[i][1]] > 0) {
                        cnt--;
                    } 
                }
                else {
                    if(colormap[queries[i][1]] == 0) cnt++;
                }
                ans.push_back(cnt);
                colormap[queries[i][1]]++;
                ballmap[queries[i][0]] = queries[i][1];
            }
        }
        for(int i =0;i<ans.size();i++) cout<<ans[i]<<" ";
        cout<<endl;
        return ans;
    }
};