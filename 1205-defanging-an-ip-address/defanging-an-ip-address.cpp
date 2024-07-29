class Solution {
public:
    string defangIPaddr(string address) {
        int ind = 0; 
        string ans ;
        while( ind < address.size()){
            if(address[ind] == '.'){
                ans += "[.]" ;
            }
            else{
                ans += address[ind];
            }
            ind ++;
        }
        return ans;
    }
};