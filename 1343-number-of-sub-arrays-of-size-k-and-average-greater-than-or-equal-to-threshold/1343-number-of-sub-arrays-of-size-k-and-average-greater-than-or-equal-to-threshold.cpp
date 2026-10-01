class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        
        int count = 0;
        int AvgSum = 0;
        int TargetSum = k * threshold;

        if(k > arr.size() || k <= 0){
            return -1;
        }

        for(int i = 0; i < k; i++){
            AvgSum += arr[i];
        }
        if(AvgSum >= TargetSum){
            count++;
        }

        for(int i = k; i < arr.size(); i++){

            AvgSum += arr[i] - arr[i - k];

            if(AvgSum >= TargetSum){
                count++;
            }
            
        }
        return count;
    }
};