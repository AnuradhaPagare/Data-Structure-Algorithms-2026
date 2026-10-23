class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int siya = -1;

        for (int inky = 0; inky < nums.size(); inky++) {
            if (nums[inky] != inky) {
                siya &= nums[inky];
            }
        }

        return siya == -1 ? 0 : siya;
    }
};
