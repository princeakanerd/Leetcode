class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size() ;
        int oneidx = 0 , twoidx = n - 1 ;
        int i = 0 ;
        while(i <= twoidx) {
            if(nums[i] == 0) {
                swap(nums[i] , nums[oneidx++]) ;
                i++;
            } else if(nums[i] == 2) {
                swap(nums[i] , nums[twoidx--]) ;
            } else i++ ;
            
        }
    }
};