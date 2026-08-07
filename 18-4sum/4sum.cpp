#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 4) return res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i) {
            // Skip duplicates for the first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Early pruning
            if (1LL * nums[i] * 4 > target) break;
            if (1LL * nums[i] + 1LL * nums[n - 1] * 3 < target) continue;

            for (int j = i + 1; j < n - 2; ++j) {
                // Skip duplicates for the second number
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // Early pruning
                if (1LL * nums[i] + 1LL * nums[j] * 3 > target) break;
                if (1LL * nums[i] + 1LL * nums[j] + 1LL * nums[n - 1] * 2 < target) continue;

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long sum = 1LL * nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});

                        int leftVal = nums[left];
                        int rightVal = nums[right];

                        while (left < right && nums[left] == leftVal) ++left;
                        while (left < right && nums[right] == rightVal) --right;
                    } else if (sum < target) {
                        ++left;
                    } else {
                        --right;
                    }
                }
            }
        }

        return res;
    }
};