#include <stack>
#include <algorithm>

class MinStack {
private:
    std::stack<std::pair<int, int>> st;

public:
    MinStack() {}
    
    void push(int value) {
        if (st.empty()) {
            st.push({value, value});
        } else {
            st.push({value, std::min(value, st.top().second)});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
