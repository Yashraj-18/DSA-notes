class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0 , high = nums.size() - 1;
        int ans = INT_MAX;
        while( low <= high ){
            int mid = (low+high)/2;
            if(nums[low] <= nums[mid]){
                // inside left sorted array , nums[low] will be the min element
                ans = min(ans, nums[low]);
                low = mid + 1; 
            }
            else{
                high = mid-1;
                ans = min(ans , nums[mid]);
            }
        }
        return ans;
    }
};