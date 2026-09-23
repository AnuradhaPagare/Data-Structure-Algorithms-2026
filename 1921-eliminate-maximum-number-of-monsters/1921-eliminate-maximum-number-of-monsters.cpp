class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();


        vector<int> arrivalTime;

        for(int i = 0; i < n; i++){
            int arrival = (dist[i] + speed[i] - 1) / speed[i];
            arrivalTime.push_back(arrival);
        }
        // sort the arrivalTime 
        sort(arrivalTime.begin(), arrivalTime.end());

        for(int i = 0; i < n; i++){
            if(arrivalTime[i] <= i){
                return i;
            }
        }
        return n;
    }
};