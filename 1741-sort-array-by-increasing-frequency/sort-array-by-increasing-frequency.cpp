class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mp;
        for(auto it : nums){
            mp[it]++;
        }
        sort(nums.begin() , nums.end() , [&](int a , int b){
            if(mp[a] != mp[b])
                return mp[a] < mp[b];   
            else return a>b;
        });
        return nums;
    }
};