class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int,int> mp;
        for(auto &it: arr){
            mp[it]++;
        }
        for(auto it: target){
            mp[it]--;
        }
        for(auto it: mp){
            if(it.second != 0) return false;
        }
        return true;
    }
};