class Solution {
public:
    string reversePrefix(string word, char ch) {
        int left = 0;
        int right = 0;
        while(word[right] != ch && right < word.length()){
            right++;
        }
        if(right == word.length()){
            return word;
        }

        while(left < right){
            char temp = word[left];
            word[left] = word[right];
            word[right] = temp;
            left ++; 
            right --;
        }
        return word;
    }
};