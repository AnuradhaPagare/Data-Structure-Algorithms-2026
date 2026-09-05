class Solution {
    public String convertToTitle(int columnNumber) {
        StringBuilder title = new StringBuilder();
        
        while (columnNumber > 0) {
            // Adjust for 1-based indexing
            columnNumber--; 
            
            // Get the remainder to find the current character
            int remainder = columnNumber % 26;
            title.append((char) ('A' + remainder));
            
            // Move to the next positional digit
            columnNumber /= 26;
        }
        
        // Reverse because characters were added from right to left
        return title.reverse().toString();
    }
}
