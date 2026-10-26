class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int volume, int k) {
        
                int n = heights.size();

        for (int v = 0; v < volume; ++v) {
            int best_pos = k;

            // 1. Try flowing left
            int i = k;
            // Walk left while terrain doesn't rise
            while (i > 0 && heights[i - 1] <= heights[i]) {
                i--;
            }
            // Scan back right from the left boundary to find the lowest reachable position
            while (i < k && heights[i] == heights[i + 1]) {
                i++;
            }
            
            // If we found a strictly lower position on the left, target it
            if (heights[i] < heights[k]) {
                heights[i]++;
                continue;
            }

            // 2. Try flowing right (if left failed)
            i = k;
            // Walk right while terrain doesn't rise
            while (i < n - 1 && heights[i + 1] <= heights[i]) {
                i++;
            }
            // Scan back left from the right boundary to find the lowest reachable position
            while (i > k && heights[i] == heights[i - 1]) {
                i--;
            }

            // If we found a strictly lower position on the right, target it
            if (heights[i] < heights[k]) {
                heights[i]++;
                continue;
            }

            // 3. Otherwise, water stays and accumulates at index k
            heights[k]++;
        }

        return heights;

    }
};
