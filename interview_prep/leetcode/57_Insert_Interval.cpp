class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int n = intervals.size();
        int i=0;
        vector<vector<int>> result;

        // Non-overlapping BEFORE
        while(i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }
        
        int start = newInterval[0], end = newInterval[1];
        while(i < n && newInterval[1] >= intervals[i][0]) {
            start = min(start,intervals[i][0]);
            end = max(end, intervals[i][1]);
            i++;
        }

        result.push_back({start, end});

        // Non-overlapping AFTER
        while(i < n) {
            result.push_back(intervals[i]);
            i++; 
        }

        return result;

    }
};
