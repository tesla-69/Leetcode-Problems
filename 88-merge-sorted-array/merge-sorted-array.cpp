class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int i = 0;
        int j = 0;
        while(i<m && j < n) {
            if(nums1[i] < nums2[j]) 
                ans.push_back(nums1[i++]);
            else 
                ans.push_back(nums2[j++]);
        }
        while(i<m) {
            ans.push_back(nums1[i++]);
        }
        while(j < n) {
            ans.push_back(nums2[j++]);
        }
        cout<<ans.size()<<endl;
        for(int i = 0; i< m+n; i++) cout<<ans[i]<<endl;
        cout<<endl;
        for(int i =0;i<m+n;i++) nums1[i] = ans[i];
        // return ans;
    }
};