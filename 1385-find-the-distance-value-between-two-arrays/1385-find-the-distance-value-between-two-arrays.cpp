class Solution {
public:
    int findTheDistanceValue(std::vector<int>& arr1, std::vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int distance_value = 0;
        
        for (int x : arr1) {
            auto it = lower_bound(arr2.begin(), arr2.end(), x - d);
            
            if (it != arr2.end() && *it <= x + d) {
                continue; 
            }
            
            distance_value++;
        }
        
        return distance_value;
    }
};
