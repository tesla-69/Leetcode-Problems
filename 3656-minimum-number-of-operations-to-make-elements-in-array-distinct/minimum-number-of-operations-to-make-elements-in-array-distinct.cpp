class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        int ind = -1;
        for(int i = n-1; i>=0; i--) {
            if(mp[nums[i]] == 0) mp[nums[i]]++;
            else {
                ind = i;
                break;
            }
        }
        cout<<ind<<endl;
        if(ind == -1) return 0;
        int ans = (ind+1) / 3;
        if((ind+1) % 3 != 0) ans++;
        return ans;
    }
};