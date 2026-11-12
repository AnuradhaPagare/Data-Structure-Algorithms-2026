class Solution {
public:
    bool checkRecord(string s) {
        int A = 0;
        int L = 0;

        for(char c : s){
            if(c == 'A'){
                A++;
                L = 0;
            }else if(c == 'L'){
                L++;
            }else{
                L = 0;
            }
            if(A >= 2 || L >= 3){
                return false;            
            }
        }
        return true;
    }
};