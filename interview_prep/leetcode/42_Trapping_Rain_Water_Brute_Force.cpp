/*

### The Intuition: "Standing on a Column"

Imagine you are standing on top of a specific bar at index `i`, and someone pours water over the entire landscape. How much water will pool directly on top of your head?

1. **You look to your left:** You walk all the way to the left edge of the board and find the **tallest building** on your left side (`left_max`).
2. **You look to your right:** You walk all the way to the right edge of the board and find the **tallest building** on your right side (`right_max`).
3. **The Spill Point:** Water can only stay on top of you if it is trapped between walls. The water level above you is capped by the **shorter** of those two tallest buildings (`min(left_max, right_max)`). If the water level rises higher than the shorter wall, it will overflow and spill out.
4. **Your Height Matters:** If your own height (`height[i]`) is shorter than that water level, the difference is the depth of the puddle sitting on you:

$$\text{Water at } i = \min(\text{max\_left}, \text{max\_right}) - \text{height}[i]$$



*(If you are taller than both or equal to them, water depth is `0`).*

### Why Brute Force is Slow (The Redundancy)

In the **Brute Force** approach, you do this process independently for **every single column**:

* You stand at column `0`, scan left and right.
* You move to column `1`, **re-scan** all the way left and right.
* You move to column `2`, **re-scan** all the way left and right again.

Notice how much work is being repeated! When you are at column `5`, you waste time re-scanning columns `0` through `4` to find the maximum height on the left, even though you already scanned most of those exact same columns when you were at column `4`.

---

### How Dynamic Programming Eliminates the Waste

The **DP approach** realizes that walking back and forth repeatedly is inefficient. Instead, it does the walking **ahead of time**:

1. **Left-to-Right Pass (`left_max` array):** You take *one single walk* from left to right, running a tally of the tallest building seen so far at each step. Now, every column instantly knows the max height to its left without re-scanning.
2. **Right-to-Left Pass (`right_max` array):** You take *one single walk* from right to left, doing the same for the right side.
3. **The O(1) Lookup:** When you finally evaluate each column, you don't scan anymore—you just look up precomputed values in your tables in $\mathcal{O}(1)$ time.

That is why DP is just brute force with **memoized/precomputed homework**!



*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total_water = 0;

        // For each bar, find the maximum height to its left and right
        for (int i = 0; i < n; ++i) {
            int left_max = 0, right_max = 0;

            // Scan left for max boundary
            for (int j = 0; j <= i; ++j) {
                left_max = max(left_max, height[j]);
            }

            // Scan right for max boundary
            for (int j = i; j < n; ++j) {
                right_max = max(right_max, height[j]);
            }

            // Water trapped at index i is determined by the shorter boundary minus its own height
            total_water += min(left_max, right_max) - height[i];
        }

        return total_water;
    }
};
