class Solution {
    
    static bool compareVectors(vector<int> &a, vector<int> &b) {
        return (a[0] < b[0]);
    }
    
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        
        sort(intervals.begin(), intervals.end(), compareVectors);
        vector<vector<int>> answer;
        
        int start = intervals[0][0], end = intervals[0][1];
        
        for(int i=1; i<intervals.size(); i++) {
            
            if (end < intervals[i][0]) {
                answer.push_back(vector<int>{start, end});
                start = intervals[i][0];
                end = intervals[i][1];
                continue;
            }
            else if (start == intervals[i][0])
                end = max(end, intervals[i][1]);
            else if (end >= intervals[i][0])
                end = max(end, intervals[i][1]);
        }
        
        answer.push_back(vector<int>{start, end});
        return answer;
        
    }
};
