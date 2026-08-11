class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return;

        // 1. Find first decreasing element from the right
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i == -1) {
            // Entire array is descending → reverse to get smallest permutation
            reverse(nums.begin(), nums.end());
            return;
        }

        // 2. Find successor to swap (first element from right > nums[i])
        int j = n - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }

        // 3. Swap nums[i] and nums[j]
        swap(nums[i], nums[j]);

        // 4. Reverse the suffix starting at i+1
        reverse(nums.begin() + i + 1, nums.end());
    }
};