class Solution {
public:
    bool isPerfectSquare(long long x) {
        long long low = 1 , high = x;
        while(low<=high){
            long long mid = (low+high)/2;
            long long val = (mid*mid);
            if(val == x) return true;
            if(val < x ){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    //    return high;
    return false;
    }
};