class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        
        priority_queue<int> pq(stones.begin(), stones.end());
        
        while(!pq.empty() && pq.size() > 1) {
            
            int stone1Weight = pq.top(); pq.pop();
            int stone2Weight = pq.top(); pq.pop();
            
            if (abs(stone2Weight-stone1Weight) > 0)
                pq.push(abs(stone2Weight-stone1Weight));
        }
        
        return pq.size() ? pq.top() : 0;
        
    }
};
