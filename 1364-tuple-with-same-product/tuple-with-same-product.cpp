class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        map<int,int> mp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1;j<n;j++){
                int temp = nums[i]*nums[j];
                mp[temp]++;
            }
        }
        long long ans = 0;
        for(auto it: mp) {
            if(it.second>=2){
                int t = it.second;
                long long pair = (t * (t-1)) / 2;
                long long sum = pair * 8;
                ans += sum;
            }
        }
        return ans;
    }
};