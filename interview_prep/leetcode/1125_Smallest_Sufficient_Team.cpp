class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int m = req_skills.size();
        int n = people.size();
        
        // Map each skill string to a bit index
        unordered_map<string, int> skill_to_id;
        for (int i = 0; i < m; ++i) {
            skill_to_id[req_skills[i]] = i;
        }
        
        // Convert each person's skills into a bitmask
        vector<int> p_mask(n, 0);
        for (int i = 0; i < n; ++i) {
            for (const string& skill : people[i]) {
                if (skill_to_id.count(skill)) {
                    p_mask[i] |= (1 << skill_to_id[skill]);
                }
            }
        }
        
        int max_mask = 1 << m;
        vector<int> dp(max_mask, INT_MAX); // dp[mask] = min people required for this skill mask
        vector<int> parent_person(max_mask, -1);
        vector<int> parent_mask(max_mask, -1);
        
        dp[0] = 0; // 0 people needed to cover 0 skills
        
        // Knapsack-style state transition over bitmask states
        for (int mask = 0; mask < max_mask; ++mask) {
            if (dp[mask] == INT_MAX) continue;
            
            // Try adding each person to the current skill mask state
            for (int i = 0; i < n; ++i) {
                int next_mask = mask | p_mask[i];
                
                // If adding person i improves the team size for next_mask
                if (dp[mask] + 1 < dp[next_mask]) {
                    dp[next_mask] = dp[mask] + 1;
                    parent_person[next_mask] = i;
                    parent_mask[next_mask] = mask;
                }
            }
        }
        
        // Backtrack from the fully covered skill state to find the team members
        vector<int> team;
        int curr = max_mask - 1;
        while (curr > 0) {
            team.push_back(parent_person[curr]);
            curr = parent_mask[curr];
        }
        
        return team;
    }
};
