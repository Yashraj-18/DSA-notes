class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        //edge case 
        int n = arr.size();
        if( n == 1 ) return 0;
        if( arr[0] > arr[1] ) return 0;
        if( arr[n-1] > arr[n-2] ) return (n-1);
        //edge case complete
        // for trimmed search space
        int low = 1 , high = n-2;
        while( low <= high ){
            int mid = ( low + high )/2;
            //if mid ele is the peak ele
            if( arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1] ){
                return mid;
            }
            else if( arr[mid] > arr[mid-1] ){
                low = mid + 1; //peak on right 
            }
            else if( arr[mid] > arr[mid+1] ){
                high = mid - 1; //peak on left
            }
            else{
                low = mid + 1 ;//this condn is for multiple peak
            }
        } 
        return -1;
    }
};