class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // group duplicates
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> used(nums.size(), false);
        backtrack(nums, used, path, result);
        return result;
    }
    
private:
    void backtrack(const vector<int>& nums, vector<bool>& used,
                   vector<int>& path, vector<vector<int>>& result) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (used[i]) continue;  // already in current path
            
            // Skip duplicates at the same level:
            // If this number equals the previous one and the previous one
            // was NOT used in the current path, then using this one would
            // create a duplicate permutation.
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }
            
            used[i] = true;
            path.push_back(nums[i]);
            backtrack(nums, used, path, result);
            path.pop_back();
            used[i] = false;
        }
    }
};