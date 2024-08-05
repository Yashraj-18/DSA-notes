class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }

        // Concatenate s to itself to create all possible rotations
        string newString = s + s;

        // Check if goal is a substring of newString
        return newString.find(goal) != string::npos;
    }
};
// method 2
// class Solution {
// public:
//     bool rotateString(string s, string goal) {
        
//         int len=s.length();
//         for(int i=0;i<len;i++)
//         {
//             s+=s[i];
//             string sub=s.substr(i+1,len+1);
//             if(sub==goal)
//             {
//                 return true;
//             }
//         }
//         return false;
//     }
// };