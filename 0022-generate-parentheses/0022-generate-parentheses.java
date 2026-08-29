import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<>();
        backtrack(result, "", 0, 0, n);
        return result;
    }

    private void backtrack(List<String> result, String current, int open, int close, int max) {
        // Base case: If the current string reaches the maximum length, it's a valid combination
        if (current.length() == max * 2) {
            result.add(current);
            return;
        }

        // Rule 1: We can always add an open parenthesis if we haven't reached the limit 'n'
        if (open < max) {
            backtrack(result, current + "(", open + 1, close, max);
        }
        
        // Rule 2: We can only add a closed parenthesis if it doesn't exceed the number of open ones
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, max);
        }
    }
}
