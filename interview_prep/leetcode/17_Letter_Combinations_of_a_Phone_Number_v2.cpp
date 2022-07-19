class Solution {
    
    void buildLetterCombination(string combination, int index, string digits, vector<string> &phoneLetters, vector<string> &letterCombinations) {

        if (index == digits.size()) {
            letterCombinations.push_back(combination);
            return;
        }

        int d = digits[index] - '0';
        for(char c : phoneLetters[d]) {
            buildLetterCombination(combination + c, index + 1, digits, phoneLetters, letterCombinations);
        }

    }
    
public:
    vector<string> letterCombinations(string digits) {
        
        if (digits == "")
            return vector<string>();
        
        vector<string> letterCombinations;
        vector<string> phoneLetters = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        string combination = "";
        
        buildLetterCombination(combination, 0, digits, phoneLetters, letterCombinations);
        
        return letterCombinations;
        
    }
};
