class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> next_greater;
        stack<int> stk;

        for (int num : nums2) {
            while (!stk.empty() && stk.top() < num) {
                next_greater[stk.top()] = num;
                stk.pop();
            }
            stk.push(num);
        }

        vector<int> ans;
        for (int num : nums1) {
            if (next_greater.count(num)) {
                ans.push_back(next_greater[num]);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};
