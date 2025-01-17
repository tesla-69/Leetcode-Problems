class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        int ans = 0 ;
        for(auto it : derived) {
            ans ^= it;
        }
        if(ans) return false;
        else return true;
    }
};