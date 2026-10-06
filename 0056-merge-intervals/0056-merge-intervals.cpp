class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // Step 1: Sort the intervals based on the start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        
        // Step 2: Insert the first interval to initialize
        merged.push_back(intervals[0]);

        // Step 3: Iterate through the rest of the intervals
        for (int i = 1; i < intervals.size(); ++i) {
            // Get the last merged interval
            vector<int>& lastMerged = merged.back();

            // If the current interval overlaps with the last merged interval
            if (intervals[i][0] <= lastMerged[1]) {
                // Merge them by updating the end time to the maximum end time
                lastMerged[1] = max(lastMerged[1], intervals[i][1]);
            } else {
                // No overlap, so just push the current interval to the list
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};
