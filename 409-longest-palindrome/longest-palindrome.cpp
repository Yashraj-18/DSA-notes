class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> lower(26,0) , upper(26,0);
        // lower and upper are two vectors which have a size of 26 and store the count of
        // lowercase or uppercase letters

        // frequency
        for ( int i = 0 ; i < s.size() ; i++) {
            // comparing ASCII value of s[i] with lowercase or uppercase letters
            if( s[i] >= 'a') {
                // updating the frequency/no. of occurrence of element
                lower[s[i] - 'a']++;
            } else {
                upper[s[i] - 'A']++;
            }
        }

        int count = 0;
        bool odd = false;
        for (int i = 0; i < 26; i++) {
            // lower
            if (lower[i] % 2 == 0) {
                // updating count with frequency of element if element is even 
                count += lower[i];
            } else {
                // updating count with frequency of element if element is odd 
                count += lower[i] - 1;
                odd = true;
            }

            // upper
            if (upper[i] % 2 == 0) {
                count += upper[i];
            } else {
                count += upper[i] - 1;
                odd = true;
            }
        }

        // if there was an odd frequency character, add 1 to the count to include one odd character
        if (odd) {
            count++;
        }

        return count;
    }
};
