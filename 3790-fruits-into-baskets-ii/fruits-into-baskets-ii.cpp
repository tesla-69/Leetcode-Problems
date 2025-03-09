class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        vector<int> flag(fruits.size(),0);
        int n = baskets.size();
        int cnt = 0;
        for(int i = 0; i< n; i++) {
            for(int j = 0; j < n; j++) {
                if(!flag[j] && fruits[i] <= baskets[j]) {
                    flag[j] = 1;
                    cnt++;
                    break;
                }
            }
        }
        return n - cnt;
    }
};