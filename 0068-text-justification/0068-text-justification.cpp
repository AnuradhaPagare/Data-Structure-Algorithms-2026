#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i = 0;
        
        while (i < words.size()) {
            int j = i + 1;
            int lineLength = words[i].length();
            
            while (j < words.size() && lineLength + 1 + words[j].length() <= maxWidth) {
                lineLength += 1 + words[j].length();
                j++;
            }
            
            string line = "";
            int numberOfWords = j - i;
            
            if (j == words.size() || numberOfWords == 1) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        line += " ";
                    }
                }
                while (line.length() < maxWidth) {
                    line += " ";
                }
            } else {
                int totalWordLength = 0;
                for (int k = i; k < j; k++) {
                    totalWordLength += words[k].length();
                }
                
                int totalSpaces = maxWidth - totalWordLength;
                int gaps = numberOfWords - 1;
                
                int baseSpaces = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;
                
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        int spacesToAdd = baseSpaces + (k - i < extraSpaces ? 1 : 0);
                        line.append(spacesToAdd, ' ');
                    }
                }
            }
            
            result.push_back(line);
            i = j;
        }
        
        return result;
    }
};
