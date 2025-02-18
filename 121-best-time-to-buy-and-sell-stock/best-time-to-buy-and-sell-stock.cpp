class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int n = prices.size();
        for(int i = n-1;i >=0; i--){
            maxi = max(maxi,prices[i]);
            int temp = maxi - prices[i];
            maxprofit = max(maxprofit,temp); 
        }
        return maxprofit;
    }
};