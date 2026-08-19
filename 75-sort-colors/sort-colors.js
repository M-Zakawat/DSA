var sortColors = function(nums) {
    let low = 0;
    let mid = 0;
    let high = nums.length - 1;

    while (mid <= high) {

        if (nums[mid] === 0) {
            // Put 0 at the beginning
            [nums[low], nums[mid]] = [nums[mid], nums[low]];

            low++;
            mid++;
        }

        else if (nums[mid] === 1) {
            // 1 is already in the middle
            mid++;
        }

        else {
            // Put 2 at the end
            [nums[mid], nums[high]] = [nums[high], nums[mid]];

            high--;
        }
    }
};