class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int i = 0, j = 0;
        long long cnt = 0;
        int subarr = 0;
        while(j < n && i < n) {
            subarr += mp[nums[j]];
            mp[nums[j]]++;
            cout<<subarr<<" ";

            while(subarr >= k) {
                cnt += n - j;
                subarr -= mp[nums[i]] - 1;
                mp[nums[i]]--;
                i++;
            }

            j++;
        }
        return cnt;
    }
};