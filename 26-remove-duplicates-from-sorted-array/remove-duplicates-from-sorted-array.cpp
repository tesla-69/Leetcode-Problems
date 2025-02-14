class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int k =0;
        set<int> s;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        k = s.size();
        int i =0;
        for(auto it: s){
            nums[i] = it;
            i++;
        }
        return k;
    }
};