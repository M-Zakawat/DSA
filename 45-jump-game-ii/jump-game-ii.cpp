class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        
        int jumps = 0;
        int curEnd = 0;      // end of current jump range
        int farthest = 0;    // farthest index reachable so far
        
        // We only need to go up to n-2; reaching or passing n-1 is enough
        for (int i = 0; i < n - 1; ++i) {
            farthest = max(farthest, i + nums[i]);
            
            // When we reach the end of the current jump's range
            if (i == curEnd) {
                ++jumps;
                curEnd = farthest;
                // Optional early exit:
                // if (curEnd >= n - 1) break;
            }
        }
        
        return jumps;
    }
};