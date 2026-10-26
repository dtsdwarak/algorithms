class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i;
            int lineLength = 0;

            // 1. Find all words that fit in the current line
            // Each subsequent word requires at least 1 space: (j - i) accounts for minimum spaces
            while (j < n && lineLength + words[j].length() + (j - i) <= maxWidth) {
                lineLength += words[j].length();
                j++;
            }

            string line = "";
            int numOfWords = j - i;
            int spacesNeeded = maxWidth - lineLength;

            // 2. Check if it's the last line OR if the line contains only 1 word
            if (j == n || numOfWords == 1) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        line += " "; // Single space between words
                    }
                }
                // Pad remaining spaces on the right
                while (line.length() < maxWidth) {
                    line += " ";
                }
            } 
            else {
                // 3. Fully justified line
                int spacesBetweenWords = spacesNeeded / (numOfWords - 1);
                int extraSpaces = spacesNeeded % (numOfWords - 1);

                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        // Distribute extra spaces to the leftmost gaps
                        int spacesToApply = spacesBetweenWords + (extraSpaces > 0 ? 1 : 0);
                        if (extraSpaces > 0) extraSpaces--;
                        
                        for (int s = 0; s < spacesToApply; s++) {
                            line += " ";
                        }
                    }
                }
            }

            ans.push_back(line);
            i = j; // Move to the next line's starting word
        }

        return ans;
    }
};
