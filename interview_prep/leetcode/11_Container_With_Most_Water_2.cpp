class Solution {
public:
    int maxArea(vector<int>& height) {

        int left =0, right=height.size() -1, bestArea=0;

        while (left < right) {
            int area = (right - left) * min(height[left], height[right]);
            bestArea = max(bestArea, area);
        
            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return bestArea;

    }
};
