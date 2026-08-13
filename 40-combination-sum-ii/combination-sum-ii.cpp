class Solution {
public:
    vector<vector<int>> result;
    vector<int> current;

    void backtrack(vector<int>& candidates, int remaining, int start) {
        if (remaining == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            // Skip duplicate values at the same recursion level
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            // Since the array is sorted, no later value can work
            if (candidates[i] > remaining)
                break;

            current.push_back(candidates[i]);

            // i + 1: each element can be used only once
            backtrack(candidates, remaining - candidates[i], i + 1);

            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                         int target) {
        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, 0);

        return result;
    }
};