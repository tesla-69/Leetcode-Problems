class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int freq1[101] = {}, freq2[101] = {}, first = 0, second = 0;
        for (int num : nums1) ++freq1[num];
        for (int num : nums2) ++freq2[num];
        for (int i = 1; i <= 100; ++i) {
            if (freq1[i] && freq2[i]) {
                first += freq1[i];
                second += freq2[i];
            }
        }
        return {first, second};
    }
};