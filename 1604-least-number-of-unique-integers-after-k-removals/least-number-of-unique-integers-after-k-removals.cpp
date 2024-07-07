#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // Step 1: Count the frequency of each number
        unordered_map<int, int> freqMap;
        for (int num : arr) {
            freqMap[num]++;
        }

        // Step 2: Sort numbers based on frequency
        vector<pair<int, int>> freqVec(freqMap.begin(), freqMap.end());
        sort(freqVec.begin(), freqVec.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
        });

        // Step 3: Remove numbers with the lowest frequency until k elements are removed
        int uniqueCount = freqVec.size();
        for (const auto& entry : freqVec) {
            if (k >= entry.second) {
                k -= entry.second;
                uniqueCount--;
            } else {
                break;
            }
        }

        // Step 4: Return the count of remaining unique integers
        return uniqueCount;
    }
};