class Solution {
public:
    int search(vector<int>& nums, int target) {
     int n = nums.size();
     int low = 0 , high = n-1;
      while(low<=high){
       int mid = (low+high)/2;
        if( nums[mid] == target) return mid;
        // if the array is left sorted 
        if( nums[low] <= nums[mid] ){
            // in the left sorted again check the smaller array is left/right sorted
            if( nums[low] <= target && target <= nums[mid] ){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        // if the array is right sorted
        else{
           if( nums[mid] <= target && target <= nums[high] ){
            low = mid + 1;
           }
           else{
            high = mid - 1;
           }

        }
      } // while loop ends here
      return -1;  
    }
};