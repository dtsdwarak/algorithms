class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        if (intervals.size() < 2)
            return intervals;

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });

        vector<vector<int>> result;
        int start = intervals[0][0], end = intervals[0][1];

        for(int i=1; i<intervals.size(); i++) {
            // current end is < next start. So we push this tuple inside.
            if (end < intervals[i][0]) {
                result.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];              
            }
            else if (end >= intervals[i][0]) {
                end = max(end, intervals[i][1]);
            }
        }
        result.push_back({start, end});

        return result;
    }
};
