#define ll long long int
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int op = 0;
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        while(pq.size()>=2 && pq.top() < k) {
            ll a = pq.top();
            pq.pop();
            ll b = pq.top();
            pq.pop();
            ll c = 2*min(a,b) + max(a,b);
            pq.push(c);
            op++;
        }
        return op;
    }
};