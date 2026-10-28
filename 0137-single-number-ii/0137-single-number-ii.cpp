class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;

        for(int num : nums){
            freq[num]++;
        }

        for(auto& pair : freq){
            if(pair.second == 1){
                return pair.first;
            }
        }

        return -1;
    }
};