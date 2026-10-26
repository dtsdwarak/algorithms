/*

The **Two-Pointer approach** is where the magic happens. It takes everything we learned from the Dynamic Programming approach and optimizes the space complexity from $\mathcal{O}(N)$ down to $\mathcal{O}(1)$ (constant space), while keeping time complexity at $\mathcal{O}(N)$.

To understand how it works, let’s look at the core realization that makes it possible.

---

### The Core Intuition: "The Shorter Wall Wins"

In the DP approach, to find the water above index `i`, we needed to know:


$$\text{Water} = \min(\text{max\_left}[i], \text{max\_right}[i]) - \text{height}[i]$$

Notice the `min()` function. It means **whichever side is shorter is the ultimate bottleneck**. If your left wall is height `3` and your right wall is height `10`, it doesn't matter that the right wall is huge—the water will spill over the left wall at height `3`. The shorter wall dictates the water level.

The Two-Pointer approach uses this rule to eliminate the need for auxiliary arrays entirely. Instead of precomputing the max heights for every single index, we start two pointers at opposite ends (`left = 0` and `right = n - 1`) and walk them inward.

---

### Step-by-Step Mental Model

1. **Two Running Maximums:** We maintain two variables: `left_max` (tracking the tallest wall seen from the left so far) and `right_max` (tracking the tallest wall seen from the right so far).
2. **Compare the Heights:** At any step, we look at `height[left]` and `height[right]`.
3. **Process the Shorter Side:**
* Suppose `height[left] < height[right]`.
* **Why does this matter?** Because `height[right]` is taller than `height[left]`, we are **guaranteed** that on the right side, there is a wall at least as tall as `height[right]`. Therefore, the bottleneck for the `left` pointer cannot possibly be worse than what's happening on the right—the left side is definitively the shorter side.
* Because of this, we don’t need to worry about what is hidden further to the right. The water level at `left` is **100% bounded and safe to calculate using `left_max**`.



---

### Walking Through the Logic

When `height[left] < height[right]`:

1. We check if the current `height[left]` is a new peak (`height[left] >= left_max`).
* If it is, we update `left_max = height[left]` (no water can sit on a peak).
* If it isn't, we know `left_max` is taller than `height[left]`, so water *must* be trapped! We calculate:

$$\text{total\_water} += \text{left\_max} - \text{height}[left]$$




2. We safely increment `left++` and repeat.

Conversely, if `height[right] <= height[left]`, we know the right side is the bottleneck. We update `right_max`, calculate water for the `right` position using `right_max - height[right]`, and decrement `right--`.

---

### Why This is Brilliant

* **No Extra Arrays:** We don't need a `left_max` array or a `right_max` array stored in memory. We just keep two single integers (`left_max` and `right_max`) that update on the fly.
* **Single Pass:** Both pointers move inward and never look backward, visiting each element at most once ($\mathcal{O}(N)$ time).

*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;

        int left = 0, right = n - 1;
        int left_max = 0, right_max = 0;
        int total_water = 0;

        while (left < right) {
            // If the left side is shorter, we process the left pointer
            if (height[left] < height[right]) {
                if (height[left] >= left_max) {
                    left_max = height[left]; // Update boundary; no water can sit on a new peak
                } else {
                    total_water += left_max - height[left]; // Trap water bounded by left_max
                }
                left++;
            } 
            // If the right side is shorter or equal, we process the right pointer
            else {
                if (height[right] >= right_max) {
                    right_max = height[right]; // Update boundary
                } else {
                    total_water += right_max - height[right]; // Trap water bounded by right_max
                }
                right--;
            }
        }

        return total_water;
    }
};
