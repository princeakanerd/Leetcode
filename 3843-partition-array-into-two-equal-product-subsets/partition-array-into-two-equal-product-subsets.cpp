class Solution {
public:
    bool f(int i , vector<int> &nums ,long long target , long long prod1 , long long prod2) {
        if(i == nums.size()){
            return prod1 == target && prod2 == target ;
        }
        if(prod1 > target || prod2 > target) return false ;

        return f(i + 1 ,nums , target ,prod1 * nums[i] , prod2) || f(i + 1 , nums ,target , prod1 , prod2 * nums[i]) ;
    }

    bool checkEqualPartitions(vector<int>& nums, long long target) {
        return f(0 ,nums , target , 1LL , 1LL ) ;
    }
};