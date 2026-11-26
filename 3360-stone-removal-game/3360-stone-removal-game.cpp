class Solution {
public:
    bool canAliceWin(int n) {
        int ston_to_remove = 10;
        int turn = 0;

        while(n >= ston_to_remove){
            n -= ston_to_remove;
            ston_to_remove -= 1;
            turn += 1;
        }
        return turn % 2 == 1;
    }
};