class Solution {
public:
    string reversePrefix(string s, int k) {

        if(k <= 1 || k > s.length())
            return s;

        int left = 0;
        int right = k - 1;

        while(left < right){
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
        return s;
    }
};