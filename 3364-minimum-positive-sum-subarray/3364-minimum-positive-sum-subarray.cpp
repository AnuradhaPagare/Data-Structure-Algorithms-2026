class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        
        int n = nums.size();
        int minsum = INT_MAX;

        for(int i = 0; i < n; i++){
            int sum = 0;

            for(int j = i; j < n; j++){
                sum += nums[j];

                int length = j - i + 1;

                if(length >= l && length <= r && sum > 0){
                    minsum = min(minsum, sum);
                }


                if(length > r){
                    break;
                }

            }
        }
        return minsum == INT_MAX ? -1: minsum;
        
    }
};