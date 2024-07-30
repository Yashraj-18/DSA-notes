
// s =    " ( () () )"
//open= 0-> 1 23 21 0

class Solution {
public:
    string removeOuterParentheses(string s) {
        int open = 0; 
        //open stores count when an '(' is encounterd and decrease it when ')' is encountered
        string removedOuterP;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                if(open > 0){
                    removedOuterP += s[i];
                }
                open++;
            }
            else {
                open--;
                if(open > 0){
                    removedOuterP += s[i];
                }
            }
        }
        return removedOuterP;
    }
};
