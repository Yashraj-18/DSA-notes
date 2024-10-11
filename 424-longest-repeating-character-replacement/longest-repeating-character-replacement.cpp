class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxlen = 0, maxf = 0;
        int hash[26] = {0};  // To count occurrences of each character
        
        while (r < s.size()) {
            hash[s[r] - 'A']++;  // Increment count of current character
            maxf = max(maxf, hash[s[r] - 'A']);  // Update max frequency
            
            // If the current window size minus the max frequency is greater than k
            if ((r - l + 1) - maxf > k) {
                hash[s[l] - 'A']--;  // Decrease count of leftmost character
                l++;  // Shrink the window from the left
            }
            
            // Update the maximum length of the valid window
            maxlen = max(maxlen, r - l + 1);
            r++;  // Expand the window to the right
        }
        
        return maxlen;
    }
};
