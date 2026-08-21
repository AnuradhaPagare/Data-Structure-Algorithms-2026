class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        // Loop through both strings from right to left
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;

            // Add digit from string a if available
            if (i >= 0) {
                sum += a[i] - '0'; // Convert char to int
                i--;
            }

            // Add digit from string b if available
            if (j >= 0) {
                sum += b[j] - '0'; // Convert char to int
                j--;
            }

            // Calculate the new bit and the new carry
            result += to_string(sum % 2);
            carry = sum / 2;
        }

        // The result is built backwards, so reverse it
        reverse(result.begin(), result.end());
        return result;
    }
};
