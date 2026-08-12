class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lowerBound(nums, target);

        // Target is not present.
        if (first == nums.size() || nums[first] != target) {
            return {-1, -1};
        }

        // Find the first element greater than target.
        int afterLast = lowerBound(nums, target + 1);

        return {first, afterLast - 1};
    }

private:
    int lowerBound(vector<int>& nums, int value) {
        int left = 0;
        int right = nums.size();

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < value) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }
};