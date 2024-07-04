class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        unordered_map<int,int> storeValues;
        for(int i=0;i<n;i++){
            storeValues[nums[i]]++;
        }
        for(auto& pair : storeValues){
            if(pair.second>n/2){
                res=pair.first;
            }
        } return res;
    }
};