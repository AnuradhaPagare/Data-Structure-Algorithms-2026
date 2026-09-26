class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool>freq(26,false);

        for(char c : sentence){
            freq[c - 'a'] = true;
        }
        for(bool seen : freq){
            if(!seen) return false;
        }
        return true;
    }
};