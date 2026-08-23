class Solution {
    public List<String> letterCombinations(String digits) {
        LinkedList<String> result = new LinkedList<>();
        
        // Edge case: return empty list for empty input
        if (digits == null || digits.isEmpty()) {
            return result;
        }
        
        // Keypad mapping where index matches the digit
        String[] mapping = new String[] {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        // Initialize the queue with an empty string anchor
        result.add("");
        
        // Process each digit in the input string
        for (int i = 0; i < digits.length(); i++) {
            int digit = Character.getNumericValue(digits.charAt(i));
            
            // Expand all current combinations in the queue for this digit layer
            while (result.peek().length() == i) {
                String currentCombination = result.remove();
                
                // Append each possible letter to the combination and push back to queue
                for (char letter : mapping[digit].toCharArray()) {
                    result.add(currentCombination + letter);
                }
            }
        }
        
        return result;
    }
}
