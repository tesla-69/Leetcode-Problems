class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        if(k > nums[0]) return -1;
        map<int,int> mp;
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(mp[nums[i]] == 0) cnt++; 
            mp[nums[i]]++;
        }
        if(nums[0] == k ) return cnt-1;
        else return cnt;

    }
};