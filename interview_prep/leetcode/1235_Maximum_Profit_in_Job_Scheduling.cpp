struct Job {
    int start;
    int end;
    int profit;

    bool operator<(const Job& other) const {
        return this->end < other.end;
    }
};

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n = startTime.size();
        vector<Job> jobs;

        // Initialize and sort jobs by endTime
        for(int i=0; i<n; i++)
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        sort(jobs.begin(), jobs.end());

        vector<int> dpProfit(n, 0);
        vector<int> endTimes;

        for(int i=0; i<n; i++)
            endTimes.push_back(jobs[i].end);

        dpProfit[0] = jobs[0].profit;

        for(int i=1; i<n; i++) {

            int start = jobs[i].start;
            int end = jobs[i].end;
            int currentProfit = jobs[i].profit;

            // Find the previous job that strictly ends before this job's start
            auto it = upper_bound(endTimes.begin(), endTimes.begin() + i, jobs[i].start);

            if (it != endTimes.begin()) {
                int prevIndex = distance(endTimes.begin(), it) - 1;
                currentProfit += dpProfit[prevIndex];
            } 
            
            // Pick the max including/excluding the current job.
            dpProfit[i] = max(currentProfit, dpProfit[i-1]);

        }

        return dpProfit[n-1];
    }
};
