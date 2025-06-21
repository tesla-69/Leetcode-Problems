class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> a(26, 0);
        for (char x : word) {
            a[x - 'a']++;
        }

        sort(a.begin(), a.end());
        vector<int> temp = a;
        int n = 26;
        for (int i = 1; i < n; i++) {
            temp[i] += temp[i - 1];
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) continue;
            int cost = 0;
            if (i - 1 >= 0) cost += temp[i - 1];

            int val = a[i] + k;
            auto it = upper_bound(a.begin(), a.end(), val) - a.begin();
            if (it != n) {
                int sum = temp[n - 1] - (it - 1 >= 0 ? temp[it - 1] : 0);
                sum -= val * (n - it);
                cost += sum;
            }
            ans = min(ans, cost);
        }
        return ans;
    }
};