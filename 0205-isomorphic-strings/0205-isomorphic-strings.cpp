class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) 
            return false;

        int s_arr[256] = {0};
        int t_arr[256] = {0};

        for(int i = 0; i < s.size(); i++){
            if(s_arr[s[i]] != t_arr[t[i]]){
                return false;
            }

            s_arr[s[i]] = i + 1;
            t_arr[t[i]] = i + 1;
        }
        return true;
    }
};