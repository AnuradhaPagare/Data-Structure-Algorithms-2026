class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int evenPrefix = 1; //already we have 0 as even number so even = 1
        int oddPrefix = 0;

        int countOdd = 0;

        int sum = 0;
        const int MOD = 1e9 + 7;

        for(int i = 0; i < arr.size(); i++){
            sum = (sum + arr[i]) % 2;

            if(sum == 1){
                countOdd = (countOdd + evenPrefix) % MOD;
                oddPrefix++;
            }else{
                countOdd = (countOdd + oddPrefix) % MOD;
                evenPrefix++;
            }
        }
        return countOdd;
    }
};