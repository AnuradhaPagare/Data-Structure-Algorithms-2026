class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1); // Base index for the first valid substring calculation
        int max_len = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    // Current ')' acts as a new base/boundary
                    st.push(i);
                } else {
                    // Calculate the length of the current valid substring
                    max_len = max(max_len, i - st.top());
                }
            }
        }

        return max_len;
            }
};
