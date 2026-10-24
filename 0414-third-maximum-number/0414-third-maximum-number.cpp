class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = LLONG_MIN;
        long long second = LLONG_MIN;
        long long third = LLONG_MIN;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == first || second == nums[i] || third == nums[i]){
                continue;
            }
            if(first < nums[i]){
                third = second;
                second = first;
                first = nums[i];                
            }else if(second < nums[i] && first > nums[i]){
                third = second;
                second = nums[i];
            }else if(third < nums[i] && second > nums[i]){
                third = nums[i];
            }
        }
        return (third == LLONG_MIN) ? first : third;
    }
};