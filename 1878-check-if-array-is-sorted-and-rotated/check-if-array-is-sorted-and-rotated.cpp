class Solution {
public:
    bool check(vector<int>& nums) {
        int dip = 0 ;

        int n = nums.size() ;

        for(int i = 1 ;i < n ; i++ ){
            if(nums[i] < nums[i - 1]) dip++ ;
        }
        if(dip == 0) return true ;
        if(dip > 1) return false ;

        if(nums[0] >= nums.back()) return true ;
        return false ;

    }
};