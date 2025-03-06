class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n+1,1), suf(n+1,1);
        int cnt = 0;
        int ind;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                cnt++;
                ind = i;
            }
        }
        if (cnt >= 2) {
            vector<int> ans(n, 0);
            return ans;
        }
        else if(cnt == 1) {
            vector<int> ans(n,0);
            for(int i =0; i<n; i++) {
                if(i == ind) ans[i] = nums[i];
            }
        }
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] * nums[i];
        }
        
        for (int i = n-1; i >= 0; i--) {
            suf[i] = suf[i + 1] * nums[i];
        }

        vector<int> ans(n,0);
        for(int i = 0 ;i < n;i++) {
            ans[i] = pre[i] * suf[i+1];
        }
        for(int i =0; i<= n; i++) {
            cout<<pre[i]<<" ";
        }
        cout<<endl;
        for(int i =0; i<= n; i++) {
            cout<<suf[i]<<" ";
        }
        cout<<endl;
        return ans;
    }
};