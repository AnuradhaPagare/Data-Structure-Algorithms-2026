class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty() || duration == 0) return 0;
        
        int totalSeconds = 0;
        
        for (size_t i = 0; i < timeSeries.size() - 1; ++i) {
            totalSeconds += min(timeSeries[i + 1] - timeSeries[i], duration);
        }
        
        totalSeconds += duration;
        
        return totalSeconds;
    }
};
