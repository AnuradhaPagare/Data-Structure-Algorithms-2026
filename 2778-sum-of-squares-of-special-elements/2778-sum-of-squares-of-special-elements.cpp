class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;

        for(int i = 0; i < n; i++){
            int position = i + 1;
            if(n % position == 0){
                total_sum += nums[i] * nums[i];
            }
        }
        return total_sum;
    }
};