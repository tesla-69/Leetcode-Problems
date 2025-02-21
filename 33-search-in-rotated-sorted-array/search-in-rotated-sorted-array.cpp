class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)>>1;
            if(nums[mid]==target)return mid;
            (nums[low]<=nums[mid]) ? ((target>=nums[low] && target<=nums[mid]) ? high=mid-1 : low=mid+1 ) : ((target>=nums[mid] && target<=nums[high]) ? low=mid+1 : high=mid-1);
        }
        return -1;
    }
};