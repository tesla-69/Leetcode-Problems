class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        std::stable_partition(nums.begin(), nums.end(), [](auto num) {
            return num >= 0;
        });
        const int middle = nums.size() / 2;
        for (int idx = 1; idx < nums.size(); ++idx) {
            const bool shouldBePositive = idx % 2 == 0;
            const bool positive = nums[idx] >= 0;
            if (shouldBePositive == positive) {
                continue;
            }
            int idxSwap = idx;
            int valSaved = nums[idxSwap];
            do {
                idxSwap = idxSwap >= middle ? 2 * (idxSwap - middle) + 1 : 2 * idxSwap;
                swap(valSaved, nums[idxSwap]);
            } while (idxSwap != idx);
        }
        return std::move(nums);
    }
};