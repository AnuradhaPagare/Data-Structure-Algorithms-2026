class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 0) return 0;
        if(n == 1) return nums[0];

       int opt1 = robOptions(nums, 0, n-2);
        int opt2 = robOptions(nums, 1, n-1);

        return max(opt1, opt2);
    }

    int robOptions(vector<int>& nums, int start, int end){
        int prev1 = 0;
        int prev2 = 0;

        for(int i = start; i<= end; i++){
            int current = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};