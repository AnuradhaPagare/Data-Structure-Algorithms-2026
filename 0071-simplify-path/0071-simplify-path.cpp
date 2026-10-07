class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        stringstream ss(path);
        string temp;
        
        while (getline(ss, temp, '/')) {
            if (temp == "" || temp == ".") {
                continue;
            }
            if (temp == "..") {
                if (!st.empty()) {
                    st.pop_back();
                }
            } else {
                st.push_back(temp);
            }
        }
        
        string res = "";
        for (const string& dir : st) {
            res += "/" + dir;
        }
        
        return res.empty() ? "/" : res;
    }
};
