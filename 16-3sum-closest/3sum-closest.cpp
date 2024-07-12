class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        sort(begin(nums), end(nums));
        for(int i = 0; i < nums.size()-2; i++){
            if(i > 0 and nums[i] == nums[i-1]) continue; 
            int tar = target-nums[i], lo = i+1, hi = nums.size()-1;
            while(lo < hi){
                int sum = nums[lo] + nums[hi] + nums[i];
                pq.push({abs(target-sum),sum});
                if(nums[lo] + nums[hi] <= tar) {
                    lo++;
                    while(lo < hi && nums[lo] == nums[lo-1]) lo++;
                }
                else {
                    hi--;
                    while(lo < hi && nums[hi] == nums[hi+1]) hi--;
                }
            }
        }
        return pq.top().second;
    }
};