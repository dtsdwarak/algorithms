class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int front=0, back=height.size() -1, volume = 0, minHeightTracked;
        
        while(front < back) {
            minHeightTracked = min(height[front], height[back]);
            volume = max(volume, (back - front) * minHeightTracked);
            while(height[front] <= minHeightTracked && front < back) front++;
            while(height[back] <= minHeightTracked && front < back) back--;
        }
        
        return volume;
        
    }
};
