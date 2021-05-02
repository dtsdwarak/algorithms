class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        stack<string> s;
        
        for(string i: logs) {
            if (i == "./")
                continue;
            else if (i == "../") {
                if (!s.empty())
                    s.pop();
            }
            else
                s.push(i);
        }
        return s.size();
    }
};
