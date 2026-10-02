class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        int n = customers.size();
        int currSaticefy = 0;
        int BaseSaticefy = 0;

        //base condition
        for(int i = 0; i < n; i++){
            if(grumpy[i] == 0){
                BaseSaticefy += customers[i];
            }
        }

        // additional saticify windo 1
        for(int i = 0; i < minutes; i++){
            if(grumpy[i] == 1){
                currSaticefy += customers[i];
            }
        }

        int maxSaticefy = currSaticefy;

        // remaining window check 
        for(int i  = minutes; i < n; i++){
            if(grumpy[i] == 1){
                currSaticefy += customers[i];
            }

            if(grumpy[i - minutes] == 1){
                currSaticefy -= customers[i - minutes];
            }

            maxSaticefy = max(maxSaticefy, currSaticefy);
        }
        return BaseSaticefy + maxSaticefy;
    }
};