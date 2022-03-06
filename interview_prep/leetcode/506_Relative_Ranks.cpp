class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
     
        priority_queue<pair<int, int>> athletesSortedByScore;
        
        for(int scoreIndex = 0; scoreIndex < score.size(); scoreIndex++)
            athletesSortedByScore.push(make_pair(score[scoreIndex], scoreIndex));
        
        vector<string> ans = vector<string>(score.size(), "");
        
        for(int scoreIndex = 0; scoreIndex < score.size(); scoreIndex++) {
            
            if (scoreIndex == 0)
                ans[athletesSortedByScore.top().second] = "Gold Medal";
            else if (scoreIndex == 1)
                ans[athletesSortedByScore.top().second] = "Silver Medal";
            else if (scoreIndex == 2) 
                ans[athletesSortedByScore.top().second] = "Bronze Medal";
            else
                ans[athletesSortedByScore.top().second] = to_string(scoreIndex+1);
             athletesSortedByScore.pop();
        }
        
        return ans;
        
    }
};
