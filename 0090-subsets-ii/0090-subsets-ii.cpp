class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result = {{}};
        int start = 0, end = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            start = (i > 0 && nums[i] == nums[i - 1]) ? end : 0;
            end = result.size();
            for (int j = start; j < end; ++j) {
                vector<int> clone = result[j];
                clone.push_back(nums[i]);
                result.push_back(clone);
            }
        }
        return result;
    }
};
