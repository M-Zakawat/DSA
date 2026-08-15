class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // Sort by starting point
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        // Add the first interval
        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {

            int currentStart = intervals[i][0];
            int currentEnd = intervals[i][1];

            int lastEnd = result.back()[1];

            // Intervals overlap
            if (currentStart <= lastEnd) {
                result.back()[1] = max(lastEnd, currentEnd);
            }
            else {
                // No overlap
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};