class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> h(26); // to store the freq of occurence
        for(int i =0 ; i< s.size() ; i++){
            h[s[i] - 'a'] ++; // stores the freq of occurence of each numbers in s string
        }
        for(int i = 0 ; i< t.size() ; i++){
            int x = --h[t[i] - 'a']; 
            // --h reduces the freq each time if the ele is encountered in the t string
            if(x < 0) return false;
        }
        return true;
    }
};