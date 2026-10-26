class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        
        for (int i = 0; i < nums.size(); i++) {
            int targetIndex = abs(nums[i]) - 1; 
            if (nums[targetIndex] > 0) {
                nums[targetIndex] = -nums[targetIndex];
            }
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                result.push_back(i + 1);
            }
        }
        
        return result;
    }
};
