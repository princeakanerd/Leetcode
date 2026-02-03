class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size() ;
        if(nums[1] <= nums[0]) return false ;
        int change = 0 ;
        bool increase = true ;
        for(int i = 2 ; i < n ;i++ ){
            if(nums[i] == nums[i - 1]) return false ;
            if(nums[i] < nums[i - 1] && increase){
                change ++ ;
                increase = false ;
            } else if(nums[i] > nums[i - 1] && !increase){
                change++ ;
                increase = true ;
            }
        }

        return change == 2;
    }
};