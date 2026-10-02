class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> set1;

        int left = 0;
        long long windowSum = 0;
        long long maxSum = 0;

        for(int right = 0; right < nums.size(); right++){

            while(set1.find(nums[right]) != set1.end()){
                windowSum -= nums[left];
                set1.erase(nums[left]);
                left++;
            }
            windowSum += nums[right];
            set1.insert(nums[right]);

            if(right - left + 1 == k){
                maxSum = max(maxSum, windowSum);

                windowSum -= nums[left];
                set1.erase(nums[left]);
                left++;
            }
        }
        return maxSum;
    }
};