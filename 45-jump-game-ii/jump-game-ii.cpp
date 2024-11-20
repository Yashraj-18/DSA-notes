

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0; // If there is only one element, no jumps are needed

        int jumps = 0;        // Count of jumps made
        int current_end = 0;  // The end of the current jump range
        int farthest = 0;     // The farthest index that can be reached

        for (int i = 0; i < n - 1; ++i) {
            // Update the farthest index that can be reached
            farthest = max(farthest, i + nums[i]);

            // If we reach the end of the current jump range
            if (i == current_end) {
                jumps++;            // Increment the jump count
                current_end = farthest; // Update the current end to the farthest reachable index

                // If the current end reaches or exceeds the last index, we're done
                if (current_end >= n - 1) break;
            }
        }

        return jumps;
    }
};
