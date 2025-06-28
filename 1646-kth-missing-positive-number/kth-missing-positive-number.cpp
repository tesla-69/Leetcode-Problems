class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int j = 0;
        int n = arr.size();
        int i;
        for(i = 1; i <= 1000; i++) {
           
            if(j < n && arr[j] != i){
                k--;
                if(k == 0) return i;
            } 
            else {
                j++;
                if(j == n) break;
            }
        }
        while(k) {
            i++;
            k--;
        }
        return i;
    }
};