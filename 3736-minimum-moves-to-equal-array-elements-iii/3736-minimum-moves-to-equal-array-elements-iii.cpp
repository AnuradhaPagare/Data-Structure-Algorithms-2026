class Solution {
public:
    int minMoves(vector<int>& nums) {

        int n = nums.size();
        int move = 0;

       
        int max1 = *max_element(nums.begin(), nums.end());

        for(int num = 0; num < n; num++){
            move += max1 - nums[num];
        }
        return move;
        
    }
};