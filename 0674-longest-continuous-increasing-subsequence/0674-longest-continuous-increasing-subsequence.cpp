class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {

        if(nums.empty()){
            return 0;
        }       

        int Maxlength = 1;
        int currentLength = 1;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i - 1]){
                currentLength++;
            }else{
                Maxlength = max(Maxlength, currentLength);
                currentLength = 1;
            }
        }
        return max(Maxlength, currentLength);
    }
};