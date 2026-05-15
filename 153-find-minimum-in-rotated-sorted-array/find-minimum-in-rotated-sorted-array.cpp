class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size() ;
        int low = 0 , high = n - 1 ;

        while(high - low > 1) {
            int mid = low + (high - low) / 2 ;

            if((nums[low] > nums[high] && nums[high] > nums[mid]) || (nums[high] > nums[mid] && nums[mid] > nums[low])) {
                high = mid;
            } else low = mid ;
        }

        return min(nums[high] , nums[low]) ;
    }
};