class Solution {
public:
  int numSubarraysWithSumLessThanOrEqualToGoal(vector<int>& nums, int goal) {
     if(goal < 0)
        return 0;

        int l = 0;
        int r = 0;
        int ans = 0;
        int n = nums.size();
        int sum = 0;

        while(r < n){
        sum += nums[r];

        while(sum > goal){
            sum -= nums[l];
            l++;
        }
        ans += (r-l+1);
        r++;
        }
        return ans;
    }   

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return numSubarraysWithSumLessThanOrEqualToGoal(nums,goal) - numSubarraysWithSumLessThanOrEqualToGoal(nums,goal - 1);
    }
};