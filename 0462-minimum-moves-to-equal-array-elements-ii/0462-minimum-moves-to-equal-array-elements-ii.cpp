class Solution {
public:
    int minMoves2(vector<int>& nums) {

        int move = 0;
        // find midian
        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());

        int median_val = nums[n / 2];

        for(int num : nums){
            move += abs(num - median_val);
        }

        return move;
    }
};