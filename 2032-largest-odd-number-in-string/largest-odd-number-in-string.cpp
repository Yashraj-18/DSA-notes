class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        bool flag;
        int r ; //stores the first odd no, do not initialize with r = 0
        for(int i = n-1; i>=0 ; i--){
            //  (char   -  char = int)&1 to find the odd no
            if( (num[i] - '0')&1 ){
                r = i;
                flag = true;
                break;
            }
        }
        if(flag){
            return num.substr(0 , r+1);
            //r+1 return the length of substring
        }
        else{
            return "";
        }
    }
};