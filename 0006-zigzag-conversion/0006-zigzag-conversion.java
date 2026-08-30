class Solution {
    public String convert(String s, int numRows) {
        // Base case: if only 1 row or string is too short, return as is
        if (numRows == 1 || s.length() <= numRows) {
            return s;
        }

        // Initialize StringBuilder for each row
        StringBuilder[] rows = new StringBuilder[numRows];
        for (int i = 0; i < numRows; i++) {
            rows[i] = new StringBuilder();
        }

        int currentRow = 0;
        boolean goingDown = false;

        // Traverse the string character by character
        for (char c : s.toCharArray()) {
            rows[currentRow].append(c);

            // Change direction when reaching the top or bottom row
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }

            // Move to the next row based on current direction
            currentRow += goingDown ? 1 : -1;
        }

        // Combine all rows into a single string
        StringBuilder result = new StringBuilder();
        for (StringBuilder row : rows) {
            result.append(row);
        }

        return result.toString();
    }
}
