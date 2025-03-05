class Solution {
public:
    int climbStairs(int n) {
        vector<int> arr(n + 1, -1); // Ensure the array size is exactly needed
        
        return helper(n, arr);
    }

private:
    int helper(int n, vector<int>& arr) {
        if (n == 0 || n == 1) return 1;
        if (arr[n] != -1) return arr[n];

        return arr[n] = helper(n - 1, arr) + helper(n - 2, arr);
    }
};
