class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256];
fill(hash, hash + 256, -1);  // Initializes all 256 elements to -1

        int l = 0,r = 0;
        int maxlen = 0;
        int n = s.size();

        if(n == 1){
            return 1;
        }
        if(n == 0){
            return 0;
        }

        while(r < n ){
            if(hash[s[r]] != -1){
                if(hash[s[r]] >= l){
                    l = hash[s[r]] + 1;
                }
            }
           int len = r-l + 1 ;
            maxlen = max(len , maxlen);
            hash[s[r]] = r;
            r++;
        }
        return maxlen;
    }
};