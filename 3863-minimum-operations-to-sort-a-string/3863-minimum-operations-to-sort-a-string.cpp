class Solution {
public:
    int minOperations(string s) {
        
        int n = s.size();

        char minS = *min_element(s.begin(), s.end());
        char maxS = *max_element(s.begin(), s.end());

        if(is_sorted(s.begin(), s.end())){
            return 0;
        } 

        // case 1: if mins at 0 and maxS at n - 1
        if(minS == s[0] || maxS == s[n - 1]){
            return 1;
        }

        if(n == 2){
            return -1;
        }

        // case 2 : if minS or maxS is at the middle
        for(int i = 1 ; i < n - 1; ++i){
            if(s[i] == minS || s[i] == maxS){
                return 2;
            }
        }
        return 3;
    }
};