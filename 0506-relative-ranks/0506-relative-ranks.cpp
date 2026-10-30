class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();

        vector<pair<int, int>>index_array(n);

        for(int i = 0; i < n; i++){
            index_array[i] = {score[i], i};
        }

        sort(index_array.begin(), index_array.end(), [](const pair<int, int>&a, const pair<int, int>& b){
            return a.first > b.first;
        });

        vector<string>result(n);

        for(int i = 0; i < n; i++){
            int index = index_array[i].second;

            if(i == 0){
                result[index] = "Gold Medal";
            }else if(i == 1){
                result[index] = "Silver Medal";
            }else if(i == 2){
                result[index] ="Bronze Medal";
            }else{
                result[index] = to_string(i + 1);
            }
        }
        return result;
    }
};