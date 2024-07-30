class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
           if (strs.empty()) return "";

        string result;

        // Sort the array
        sort(strs.begin(), strs.end());

        // Get the first and last strings
        string first = strs.front();
        string last = strs.back();

        // Start comparing
        for (size_t i = 0; i < first.length(); i++) {
            if (first[i] != last[i])
                break;
            result += first[i];
        }

        return result;
    }
};