class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a = nums[0], b = nums[1], c = nums[2];
        if(a == b && a == c) return "equilateral";
        else if((a + b > c) && (a == b || a == c || b == c)) return "isosceles";
        else if(a + b > c) return "scalene";
        else return "none";
    }
};