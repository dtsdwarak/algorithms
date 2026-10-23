class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        if (magazine.length() < ransomNote.length())
            return false;

        unordered_map<char, int> freq;
        
        for(const char& a: magazine) {
            if (freq.count(a))
                freq[a]++;
            else
                freq[a] = 1;
        }

        for(const char &a: ransomNote) {
            if (!freq.count(a))
                return false;
            freq[a]--;
        }

        for(auto& item: freq) {
            if (item.second < 0)
                return false;
        }

        return true;

    }
};
